#include<iostream>
#include<algorithm>
#include<cstring>
using namespace std;
//ifstream cin("replace.in");
//ofstream cout("replace.out");
int n,q,chang[20005]={},du=0,sum=0;
string a[200005][2]={},t[2]={},x,mm;
bool eee(int q,int w,int r){
	int p=0;
	while(t[r][p+q]==a[w][1][p]&&p<chang[w]){
		p++;
		if(t[r][q+p]!=a[w][1][p]){
			return false;
		}
	}
	return true;
}
void dfs(int r,int kaishi){
	for(int i=kaishi;i<du;i++){
		for(int j=1;j<=n;j++){
			if(t[1][i]==a[j][1][0]){
				if(eee(i,j,r)){
					mm=t[1];
					for(int k=0;k<=chang[j];k++){
						t[1][i+k]==a[j][1][k];
					}
					if(x==t[2]){
						sum++;
					}
					t[1]=mm;
				}
			}
		}
	}
}
int main(){
	cin>>n>>q;
	for(int i=1;i<=n;i++){
		cin>>a[i][1]>>a[i][2];
		chang[i]=a[i][1].length();
	}
	for(int i=1;i<=q;i++){
		sum=0;
		cin>>t[1]>>t[2];
		du=t[1].length();
		dfs(i,0);
		cout<<sum;
	}
//	cin.close();
//	cout.close();
	return 0;
}
