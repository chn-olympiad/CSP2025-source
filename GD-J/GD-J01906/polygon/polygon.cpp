#include<bits/stdc++.h>
using namespace std;
int a,d[1000],sum=0,mq[1000]={},xq[1000]={},ac=1;
bool ok(){
	int os=0,om=-1,l=0;
	for(int i=0;i<a;i++){
		if(mq[i]>om){
			om=mq[i];
		} 
		os+=mq[i];
	}
	if(os>om*2 && l>=3){
		return true;
	}else{
		return false;
	}
}
int bfs(int zxzrpz){
	int l=0;
	for(int i=zxzrpz;i<a;i++){
		if(xq[i]==0){
			xq[i]=1;
			mq[i]=d[i];
			bfs(i); 
			mq[i]=0;
			xq[i]=0;
		}
	} 
	for(int i=0;i<a;i++){
		if(xq[i]==1){
			l++;
		}
	}
	int os=0,om=-1,p=0;
	for(int i=0;i<a;i++){
		if(mq[i]>om){
			om=mq[i];
		} 
		os+=mq[i];
	}
	if(os>om*2 && l>=3){
		p=1;
	}
	if(l>=3 && p==1){
		sum++;
	}
	return 0;
}
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>a;
	for(int i=0;i<a;i++){
		cin>>d[i];
	}
	bfs(0);
	cout<<sum%998244353;
	return 0;
} 
