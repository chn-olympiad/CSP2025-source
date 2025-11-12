#include<bits/stdc++.h>
using namespace std;
struct fffff{
	int numberf;
	int pointf;
};
bool cmp(fffff x,fffff y){
	return x.pointf>y.pointf;
}
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	int n,m;
	cin>>n>>m;
	vector<fffff> a(n*m);
	for(int i=0;i<n*m;i++){
		cin>>a[i].pointf;
		a[i].numberf=i;
	}
	sort(a.begin(),a.end(),cmp);
	int x=-1;bool flag=1;
	for(int i=1;i<=m;i++){
		if(i%2){
			for(int j=1;j<=n;j++){
				x++;
				if(a[x].numberf==0){
					cout<<i<<" "<<j<<endl;
					return 0;
				}
			}
		}
		else{
			for(int j=n;j>=1;j--){
				x++;
				if(a[x].numberf==0){
					cout<<i<<" "<<j<<endl;
					return 0;
				}
			}
		}
	}
	return 0;
} 
