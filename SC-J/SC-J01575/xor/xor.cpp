#include<bits/stdc++.h>
using namespace std;
int n,k,a[5000005],ans;

string ejz(int x){
	string s1;
    while(x>0){
    	s1+=x%2+'0';
    	x/=2;
	}
	return s1;
}

int sjz(string s1){
	int x=0,y=1;
	for(int i=0;i<s1.size();i++){
	   x+=(s1[i]-'0')*y;
	   y*=2;	
	}
	return x;
}

int yh(int x,int y){
	string s1,s2,s3;
	s1=ejz(x);s2=ejz(y);
	for(int i=0;i<max(s1.size(),s2.size());i++){
		if(s1[i]!=s2[i]){
			s3+='1';
		}else{
			s3+='0';
		}
	}
	return sjz(s3);
}
 
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	scanf("%d %d",&n,&k);
	for(int i=1;i<=n;i++){
		scanf("%d",&a[i]);
	}
	int l=0,r=n+1;
	for(int i=1;i<=n;i++){
		int x;bool f=1;
		for(int j=1;j<=n-i+1;j++){
			for(int g=j;g<i+j;g++){
			    if(a[g]==-1) f=0;
			}
			if(f){
			if(i==1) 
			  {
			x=a[j];
			  }else if(i==2){
			  	x=yh(a[j],a[j+1]);
			  }else{
			  x=yh(a[j],a[j+1]);
			  for(int h=j+2;h<=j+i;h++) x=yh(x,a[h]);  	
			  }
			if(x==k)
			  {
				ans++;
			    for(int g=j;g<i+j;g++) a[g]=-1;	
			  }	
			}
			f=1;	
		}
	}
	printf("%d",ans);
	return 0;
}
