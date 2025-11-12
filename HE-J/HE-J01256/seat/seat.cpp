#include <bits/stdc++.h>
using namespace std;
long long n,m;
vector<long long> a;
long long ans[15][15];
bool cmp(int a,int b){
	return a>b;
}
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	for(int i=0;i<n*m;i++){
		int s;
		cin>>s;
		a.push_back(s);
	}
	int import=a[0];
	sort(a.begin(),a.end(),cmp);
	int pos=0;
	bool p=true;
	for(int i=1;i<=n;i++){
		if(p){
			for(int j=1;j<=m;j++){
				ans[j][i]=a[pos];
				pos++;
			}
			
		}
		else{
			for(int j=m;j>=1;j--){
				ans[j][i]=a[pos];
				pos++;
			}
		} 
		p=!p;
	}
	int ansx=0,ansy=0;
	for(int i=1;i<=n;i++){
		bool t=false;
		for(int j=1;j<=m;j++){
			if(ans[i][j]==import){
				ansx=i;
				ansy=j;
				t=true;
				break;
			}
		}
		if(t){
			break;
		}
	}
	cout<<ansy<<" "<<ansx<<endl;
	fclose(stdin);
	fclose(stdout);
	return 0;
}
