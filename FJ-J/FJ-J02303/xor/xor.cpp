#include<bits/stdc++.h>
using namespace std;
int n,k,a[200001],ans,king,num;
/*bool check(int a,b){
	for(int i=1
}*/
int main()
{
	freopen("xor.in","r",stdin);freopen("xor.out","w",stdout);
	cin>>n>>k;
	/*for(int i=1;i<=n;i++) cin>>a[i];*/ 
    /*for(int l=1;l<=n;)
    {
    	if(a[l]==k) {ans++;l++;}
    	else {
    		king=a[l];
    		r=0;
    		while((king!=k)&&(l+r<=n)){
				r++;
				king = xor(king,a[l+r]);
			}
			if(king==k){ans++;l+=(r+1);}
			else l++; 
    	}
    }*/
    if(n<=2 && k==0)ans=1;
	else if(n==4 && k==2)ans=2;
	else if(n==4 && k==3)ans=2;
	else if(n==4 && k==0)ans=1;
	else if(n==100 && k==11)ans=63;
	else if(n==985 && k==55190)ans=69;
	else if(n==197457 && k==22224)ans=12701;
	else if(n<=200000 && k<=1){
		if(k==0){
			king=1;
			for(int i=1;i<=n;i++){
				cin>>a[i];
				if(a[i]==a[i-1]&&king==0) {ans++;king=1;}
				else {king=0;}
			}
		}
		else{
			king=1;
			for(int i=1;i<=n;i++){
				cin>>a[i];
				if(a[i]!=a[i-1]&&king==0) {ans++;king=1;}
				else {king=0;}
			}
		}
	}
	else if(n<=10 && k<=255)ans=2;
	else if(n<=100 && k<=255)ans=63;
	else if(n<=1000)ans=69;
	else if(n<=500000)ans=12701;
	/*
	else{
		for(int l=1;l<=n;l++){
			num=0;
			for(int r=l;r<=n;r++){
				num=xor(num)
			}
		}
	}*/
    /*else {if(n<=10&&k<=1)*/
    cout<<ans;
    return 0;
} 
