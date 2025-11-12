#include<bits/stdc++.h>
using namespace std;
int n,m;
long long key=0;
long long a[1086][1086];
long long k[10086];
bool cmp(long long a,long long b){
	return a>b;
}
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	int x=n*m;
	for(int i=1;i<=x;i++){
		cin>>k[i];
	}
	key=k[1];
	sort(k+1,k+1+x,cmp);
	int h=1;
	int hk=1;
	int l=1;
	bool lk=0;
	for(int i=1;i<=x;i++){
		a[h][l]=k[i];
		if(k[i]==key){
			cout<<l<<" "<<h;
			break;
		}
		if(lk==1){
			l++;
			lk=0;
			hk=0-hk;
			continue;
		}
		if(h+hk==n||h+hk==1){
			lk=1;
		}
		h=h+hk;
	}
	/*for(int i=1;i<=n;i++){
		for(int j=1;j<=m;j++){
			cout<<a[i][j]<<" ";
		}
		cout<<endl;
	}*/
	fclose(stdin);
	fclose(stdout);
}
