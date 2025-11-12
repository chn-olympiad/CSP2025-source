#include<bits/stdc++.h>
using namespace std;
long long n,m;
long long a[100009];
long long v[109][109];
bool cmp(int a,int b){
	return a>b;
}
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n*m;i++){
		cin>>a[i];
	}
	int b=a[1];//存a[1]
	sort(a+1,a+n*m+1,cmp);
	bool f=false;//判断自下而上还是自上而下，初始为向下
	int k=1;
	for(int i=1;i<=n;i++){
		if(f==false){//向下
			for(int j=1;j<=m;j++){
				v[i][j]=a[k];
				k++;
			}
			f=true;
		}
		else if(f==true){//向上
			for(int j=m;j>=1;j--){
				v[i][j]=a[k];
				k++;
			}
			f=false;
		}
		cout<<endl;
	}
	for(int i=1;i<=n;i++){
		if(f==false){//向下
			for(int j=1;j<=m;j++){
				if(v[i][j]==b){
					cout<<i<<" "<<j;
				}
			}
			f=true;
		}
		else if(f==true){//向上
			for(int j=m;j>=1;j--){
				if(v[i][j]==b){
					cout<<i<<" "<<j;
				}
			}
			f=false;
		}
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
