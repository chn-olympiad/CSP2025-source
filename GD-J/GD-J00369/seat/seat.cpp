#include<bits/stdc++.h>
using namespace std;
int g[20][20],n,m;
int s[110];
int f;
int num;
int p;
bool cmp(int a,int b){
	return a>b;
}
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	p=n*m;
	for(int i=1;i<=p;i++){
		cin>>s[i];
		if(i==1){
			num=s[i];
		}
	}
	sort(s+1,s+1+p,cmp);
	int tt=1;
	for(int i=1;i<=n;){
		for(int j=1;j<=m;){
			if(s[tt]==num){
				cout<<j<<" "<<i;
				return 0;
			}
			if(f==0){
				if(i==n){
					f=1;
					j++;
				}else{
					i++;
				}
			}else{
				if(i==1){
					f=0;
					j++;
				}else{
					i--;
				}
			}
			tt++;
		}
	}
	return 0;
}

