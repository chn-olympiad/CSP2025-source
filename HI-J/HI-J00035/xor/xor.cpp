#include<bits/stdc++.h>
using namespace std;
int n,k,cnt;int a[500005];
bool yan(int n){
	for(int i=1;i<=n;i++){
		if(a[i]!=1)return 0;
	}return 1;
}
int yh(int a,int b){
	string aa="";
	string bb="";
	string cc="";
	while(a!=0){
		if(a%2==1){
			aa=aa+"1";
		}else aa=aa+"0";
		a/=2;
	}while(b!=1){
		if(b%2==0){
			bb=bb+"1";
		}else bb=bb+"0";
		b/=2;
	}int line=max(aa.size(),bb.size());
	if(aa.size()<line){
		for(int i=1;i<=line-aa.size();i++)aa="0"+aa;
	}if(bb.size()<line){
		for(int i=1;i<=line-bb.size();i++)bb="0"+bb;
	}for(int i=1;i<=line;i++){
		if(aa[i]!=bb[i]){
			cc="1"+cc;
		}else cc="0"+cc;
	}int sum=0,o=0;
	for(int i=cc.size()-1;i>=0;i--,o++)sum+=((cc[i]-'0')*pow(2,o));
	return sum;
}
int xdf(){int sum=0;bool qian=0;int qo=0;
	for(int i=1;i<=n;i++){
		if(a[i]==k&&qian==0){
			sum++;
		}else if(qian==0){
			qian=1;qo=a[i];
		}else if(qian==1){
			qo=yh(qo,a[i]);
			if(qo==k){sum++;qian=0;qo=0;}
		}
	}if(qo==0){
		return sum;
	}
}
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>k;
	for(int i=1;i<=n;i++)cin>>a[i];
	if(yan(n)==1){if(k==0)cout<<n;else cout<<0;return 0;}
	cout<<xdf();
	return 0;
}
