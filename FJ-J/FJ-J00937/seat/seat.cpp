#include<bits/stdc++.h>
using namespace std;
int n,m;
int a[10005];
int jl;
int l=1,h=1;//ÁÐ ÐÐ 
bool cmp(int a,int b){return a>b;}
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n*m;i++)cin>>a[i];
	jl=a[1];
	sort(a+1,a+1+n*m,cmp);
	for(int i=1;i<=n*m;i++){
		if(a[i]==jl){
			cout<<l<<' '<<h;
			return 0;
		}
		if(l%2==0){
			h--;
			if(h==0){
				l++;
				h=1;
			}
		}else{
			h++;
			if(h==n+1){
				l++;
				h=n;
			}
		}
	}
	return 0;
}

