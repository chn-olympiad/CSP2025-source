#include<bits/stdc++.h>
using namespace std;
struct area{
	int sta,end;
}l[500005];
int a[500005];
bool compare(area a,area b){
	return a.end<b.end;
}
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	int n,k;
	cin>>n>>k;
	for(int i=1;i<=n;i++)
		cin>>a[i];
	int num=1;
	for(int i=1;i<=n;i++){
		int c=1e9;
		l[num].sta=i;
		if(a[i]==k){
			l[num++].end=i;
			continue;	
		}
		else{
			int sum=a[i];
			for(int j=i+1;j<=n;j++){
				sum=(sum ^ a[j]);
				if(sum==k){
					c=j;
					break;
				}
			}
			l[num++].end=c;
		}
	}
	num--;
	sort(l+1,l+num+1,compare);
	int cnt=1,e=l[1].end;
	for(int i=2;i<=num;i++)
		if(l[i].sta>e && l[i].end!=1e9){
			cnt++;
			e=l[i].end;
		}
	cout<<cnt;
	return 0;
} 