#include<bits/stdc++.h>
using namespace std;

int nu[10001];
bool cmp(int a,int b){
	return a>b;
}
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	int n,m;
	cin>>n>>m;
	for(int i=0;i<n*m;i++)
		cin>>nu[i];
	int t=nu[0];
	sort(nu,nu+n*m,cmp);
	int le=1,li=0,he=0;
	for(int i=0;i<n*m;i++){
		if(nu[i]==t){
			int sh=le/n,y=le%n;
			if(y==0){
				he=n;
				li=-1;
			}
			else if(sh%2==1)
				he=n-y+1;
			else
				he=y;
			li=sh+1;
			break;
		}
		le++;
	}
	cout<<li<<" "<<he;
}
