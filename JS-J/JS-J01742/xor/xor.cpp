#include <bits/stdc++.h>
using namespace std;
int n,k,a[500005],s[500005],ansnum=0;
bool flag=true;
int cxor(int x1,int y1){
	int x=max(x1,y1),y=min(x1,y1),num=0;
	string a="",b="",ans="";
	for(int k=32768;k>1;k/=2){
		if(k<=x){
			x-=k;
			a="1"+a;
		}
		else{
			a="0"+a;
		}
		if(k<=y){
			y-=k;
			b="1"+b;
		}
		else{
			b="0"+b;
		}
		if(x==0&&y==0){
			break;
		}
	}
	int cpos;
	for(int cpos=a.length()-1;cpos>=0;cpos--){
		if(a[cpos]!=b[cpos]){
			ans+="1";
		}
		else{
			ans+="0";
		}
	}
	for(int cpos=int(b.length());cpos<=int(a.length());cpos++){
		if(a[cpos]=='1'){
			ans="1"+ans;
		}
		else{
			ans="0"+ans;
		}
	}
	cpos=0;
	for(int k=1;k<=32768;k*=2){
		if(cpos>=int(ans.length())){
			break;
		}
		if(ans[cpos]=='1'){
			num+=k;
		}
		cpos++;
	}
	return num;
}
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>k>>a[1];
	s[1]=a[1];
	for(int i=2;i<=n;i++){
		cin>>a[i];
		s[i]=cxor(s[i-1],a[i]);
	}
	int pos;
	for(int i=1;i<=n;i++){
		if(flag){
			pos=s[i];
			flag=true;
		}
		if(s[i]-pos==k){
			ansnum++;
			flag=false;
		}
	}
	cout<<ansnum;
	return 0;
}
