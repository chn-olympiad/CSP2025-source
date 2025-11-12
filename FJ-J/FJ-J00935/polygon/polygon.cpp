#include<bits/stdc++.h>
using namespace std;
int n,a[10005],s=0;
void mode(int l,int r,int v,int t){
	if(v>1){
		for(int i=l;i<=r+1-v;i++){
			mode(i+1,r,v-1,t+a[i]);
		}
	}
	else{
		for(int i=l;i<=r;i++){
			if(2*a[i]<t+a[i]) s++;
			mode(i+1,r,0,t+a[i]);
		}
	}
}
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+1+n);
	//5 2 2 3 8 10
	mode(1,n,3,0);
	cout<<s;
	fclose(stdin);fclose(stdout);
	return 0;
}
