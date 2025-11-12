#include<bits/stdc++.h>
using namespace std;
int n,k;
int a[500005],jg=0;
string az[500005];

string xh(string x,string y){
	string jg="";
	int as=min(x.size(),y.size());
	int aa=max(x.size(),y.size());
	for(int i=1;i<=aa-as;i++){
		if(x.size()<y.size()){
			x=x+"0";
		}else{
			y=y+"0";
		}
	}
	for(int i=0;i<aa;i++){
		if(x[i]==y[i]){
			jg=jg+"0";
		}else{
			jg=jg+"1";
		}
	}
	
	return jg;
}

int a210(string x){
	int as=x.size();
	int jg=0;
	for(int i=0;i<as;i++){
		int s=i;
		jg=jg+pow(2,s)*(x[i]-'0');
	}
	return jg;
}

int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>k;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		if(a[i]==k){
			jg++;
		}
		int aa=a[i];
		while(1){
			if(aa<=0){
				break;
			}
			if(aa%2==0){
				az[i]=az[i]+"0";
			}else{
				az[i]=az[i]+"1";
			}
			aa=aa/2;
		}
		int as=az[i].size();
		if(as%4!=0){
			for(int j=1;j<=4-as%4;j++){
				az[i]=az[i]+"0";
			}
		}
	}
	
	for(int i=1;i<=n;i++){
		string axh=az[i]; 
		if(a[i]!=k){
			int j=1;
			while(1){
				if(a[i+j]==k||i+j>n){
					break;
				}else{
					int axg=a210(xh(axh,az[i+j]));
					if(axg==k){
						jg++;
						break;
					}
				}
				j++;	
			}
		}
	}
	cout<<jg;
	return 0;
}

