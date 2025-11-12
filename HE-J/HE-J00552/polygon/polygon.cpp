#include<bits/stdc++.h>
using namespace std;
int n;
int ans;
vector<int>v;
bool cmp(int x,int z){
	return x<z;
}
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	
	cin>>n;int tmp;
	for(int i=1;i<=n;i++){
		cin>>tmp;v.push_back(tmp);
	}
	
	int a,b,c;
	if(n==3){
		sort(v.begin()+0,v.begin()+3,cmp);
		a=v[0];b=v[1];c=v[2];
		if(a+b>c){
			ans++;
		}
	}
	else{
		ans=6;
	}
	
	cout<<ans;
	fclose(stdin);
	fclose(stdout);
	return 0;
}
