#include<bits/stdc++.h>

using namespace std;
int a[12][12];
int r;
int s[110];
bool cmp(int x,int y){
	return x>y;
}
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	int n,m;
	cin>>n>>m;
	if(m<=10){
		for(int i=0;i<n*m;i++){
		cin>>s[i];
		}
	}else{
		s[0]=m%100;
		m/=100;
		for(int i=1;i<n*m;i++){
			cin>>s[i];
		}
	}
	r=s[0];
	sort(s,s+m*n,cmp);
	int temp=0;
	for(int i=0;i<m;i++){
		if(i%2==0){
			for(int j=0;j<n;j++){
				if(s[temp]==r){
					cout<<i+1<<' '<<j+1;
					return 0;
				}
				a[i][j]=s[temp];
				temp++;
			}
		}else{
			for(int j=n-1;j>=0;j--){
				if(s[temp]==r){
					cout<<i+1<<' '<<j+1;
					return 0;
				}
				a[i][j]=s[temp];
				temp++;
			}
		}
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
