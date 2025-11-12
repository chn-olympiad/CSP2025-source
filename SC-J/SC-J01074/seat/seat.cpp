#include<bits/stdc++.h>
using namespace std;
int a[1005];
int main(){
	ios::sync_with_stdio(false),cin.tie(0),cout.tie(0);
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	int n,m;
	cin>>n>>m;
	for(int i=0;i<n*m;i++){
		cin>>a[i];
	}
	int tmp=a[0];
	sort(a,a+n*m,greater<int>());
	int ansx=0,ansy=0;
	int flag=1;
	for(int i=0;i<n*m;i++){
		if(a[i]==tmp)break;
		if(ansx==n-1&&flag!=-1){
			flag=-1;
			ansy++;
		}
		else if(ansx==0&&flag!=1){
			flag=1;
			ansy++; 
		}
		else ansx+=flag;
//		cout<<ansx<<' '<<ansy<<'\n';
	}
	cout<<ansy+1<<' '<<ansx+1;
	return 0;
}
