#include <bits/stdc++.h>
using namespace std;
const int N=5e5+5;
int n,k;
int a[N],xorS[N];

struct Xor{
	int begin;
	int end;
} e[N];

bool cmp(Xor x,Xor y){
	return x.end<y.end;
}

int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	
	cin>>n>>k;
	for (int i=1;i<=n;i++){
		cin>>a[i];
	}
	
	int idx=0;
	for (int len=1;len<=n;len++){
		for (int i=1;i+len-1<=n;i++){
			xorS[i]=xorS[i]^a[i+len-1];
			if (xorS[i] == k){
				e[++idx].begin=i;
				e[idx].end=i+len-1;
			}
		}
	}
	
	sort(e+1,e+1+idx,cmp);
	int now_end=0,Sum=0;
	for (int i=1;i<=idx;i++){
		if (e[i].begin > now_end){
			now_end=e[i].end;
			Sum++;
		}
	}
	cout<<Sum<<"\n";
	
	fclose(stdin);
	fclose(stdout);
	return 0;
} 
