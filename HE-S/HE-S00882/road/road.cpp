#include<bits/stdc++.h>
using namespace std;
int a[100000],b[10010][10001],c[100000],d[100000],s[10000];
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	int n,m,k,num1=0,num2=1e9,num=0,h=0,v=0;
	cin>>n>>m>>k;
	for(int i=1;i<=m;i++){
		cin>>a[i]>>c[i]>>d[i];
	}
	for(int i=1;i<=k;i++){
		for(int j=0;j<=n;j++){
		cin>>b[i][j];
		}
	}
	for(int i=1;i<=m;i++){
		for(int j=1;j<=i;j++){
			if(d[i]>=d[j]){
				swap(d[i],d[j]);
				swap(a[i],a[j]);
				swap(c[i],c[j]);
			}
		}
	}
	for(int i=1;i<=k;i++){
		for(int j=0;j<=i;j++){
			if(b[i][0]>=b[j][0]){
				swap(b[i][0],b[j][0]);
			}
		}
	}
	for(int j=0;j<=n;j++){
		num+=b[1][j];
	}
	for(int i=1;i<=m;i++){
		h=0;v=0;
	for(int j=1;j<=i;j++){
		if(a[i]==s[j]){
			h++;
			break;
		}
	}
	for(int j=1;j<=i;j++){
		if(c[i]==s[j]){
			v++;
			break;
		}
	}
	if(h==0){
		s[i]=a[i];
	}
	if(v==0){
		s[i+1]=c[i];
	}
	if(h!=0&&v!=0){
	}
	else if(h==0||v==0){
			num1+=d[i];
	}
	}
	for(int i=1;i<=m;i++){
			num2=min(b[1][i-1]+d[i],num2);
		}
	cout<<min(num,min(num1,num2));
	return 0;
}
