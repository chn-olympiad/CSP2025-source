#include<bits/stdc++.h>
using namespace std;


int read(){
	int w = 1,s = 0;
	char ch = getchar();
	while(ch<48||ch>57){
		if(ch=='-')w = -1;
		ch = getchar();
	}
	while(ch>=48&&ch<=57){
		s = (s<<1)+(s<<3)+(ch^48);
		ch = getchar();
	}
	return w*s;
}

const int N = 500010;

int n,k,a[N],fl = 1;

bool check(int x){
	int cnt = 0,lst = 0,tek = 0;
	for(int i = 1;i <= x;++i){

		for(int j = lst +1;j <= n;++j){
			int sum = 0;
			for(int l = j;l <= n;++l){
				if(l==j)sum = a[l];
				else sum = sum xor a[l];
				if(sum==k){
					lst = l;
					break;
				}
			}
			if(sum==k){
				cnt++;
				break;
			}
			
		}
	}
	if(cnt>=x)return true;
	else return false;
}

int fl2 = 0,rts = 0,pts = 0,pf = 0,cts = 0;
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	n = read(),k = read();
	for(int i = 1;i <= n;++i){
		a[i] = read();
		if(a[i]!=k)fl = 0;
		if(a[i]!=1)fl2 = 0;
		if(a[i]==1)rts++;
		if(a[i]==0)pts++;
	}
	for(int i = 1;i <= n;++i){
		if(a[i]==1&&pf==0){
			pf = 1;
		}
		if(pf==1&&a[i]==0){
			cts++;
			pf = 0;
		}
	}
	if(fl){
		cout<<n;
		return 0;
	}
	if(fl2){
		cout<<n/2;
		return 0;
	}
	if(k<=1){
		if(k==1){
			cout<<rts;
			return 0;
		}
		if(k==0){
			cout<<cts+pts;
			return 0;
		}
	}
	int l = 1,r = n-1;
	while(l<r){
		int mid = (l+r)>>1;
		if(check(mid)){
			l = mid+1;
		}else{
			r = mid;
		}
	}
	cout<<l-1;
	return 0;
}