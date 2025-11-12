#include<bits/stdc++.h>
using namespace std;
bool cmp(int x,int y){
	if(x>y){
		return true;
	}else{
		return false;
	}
}
int main(){
	//freopen("number.in","r",stdin);
	//freopen("number.out","w",stdout);
	int s,a[100001],f=0;
	cin>>s;
	for(int i=0;s!=0;i++){
		a[i]=s%10;
		f+=1;
		s/=10;
	}
	sort(a,a+f+1,cmp);
	for(int i=0;i<f;i++){
		cout<<a[i];
	}
	return 0;
}
