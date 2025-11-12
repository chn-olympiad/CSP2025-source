#include<bits/stdc++.h>
using namespace std;
string s;
string a[600000][30];
string b[30];
string c[30];
string d[30];
string v[30];
long long f[30];
long long l,n,m,r,rs,k,luo,ml;
long long x2,y2,cl;
long long duanshu,flag3;
long long o[600000];
bool jc(long long x){
	long long flag=0;
	for(long long i=1;i<=x;i++){
		if(c[i]!=b[i]){
			flag=1;
		}
	}
	if(flag==0){
		return true;
	}
	else{
		return false;
	}
}
void ic(long long x,long long y,long long ll){
	if(x>y){
		for(long long i=1+x-y;i<=x;i++){
			if(c[i]==a[ll][i-(x-y)]){
				c[i]='0';
			}
			else{
				c[i]='1';
			}
		}
		cl=x;
	}
	else if(x==y){
		for(long long i=1;i<=x;i++){
			if(c[i]==a[ll][i]){
				c[i]='0';
			}
			else{
				c[i]='1';
			}
		}
		cl=x;
	}
	else{
		for(long long i=1+y-x;i<=y;i++){
			if(c[i-(y-x)]==a[ll][i]){
				a[ll][i]='0';
			}
			else{
				a[ll][i]='1';
			}
		}
		cl=y;
		for(long long i=1;i<=cl;i++){
			c[i]=a[ll][i];
		}
	}
}
int main(){
	freopen("xor.in","r",stdin);
    freopen("xor.out","w",stdout);
	cin>> n >> k;
	l=0;
	r=k;
	while(1){
		l++;
		d[l]=char(r%2+'0');
		r/=2;
		if(r==0){
			break;
		}
	}
	for(long long i=1;i<=l;i++){
		b[l-i+1]=d[i];
	}
	luo=l;
	for(long long i=1;i<=n;i++){
		cin>> o[i];
		l=0;
		r=o[i];
		while(1){
		    l++;
		    d[l]=char(r%2+'0');
		    r/=2;
		    if(r==0){
			    break;
		    }
		}
		for(long long j=1;j<=l;j++){
		    a[i][l-j+1]=d[j];
	    }
	    f[i]=l;
	    if(i==1){
			for(long long j=1;j<=l;j++){
		        c[j]=a[1][j];
			}
			cl=l;
	    }
	}
	for(long long i=2;i<=n;i++){
		if(flag3==1){
			for(long long j=1;j<=f[i];j++){
				c[j]=a[i][j];
			}
			flag3=0;
			continue;
		}
		if(cl==luo){
			if(jc(cl)){
				duanshu++;
				cl=f[i];
				for(long long j=1;j<=cl;j++){
					c[j]=a[i][j];
				}
				continue;
			}	
		}
		else if(k==o[i]){
			duanshu++;
			flag3=1;
			continue;
		}
		ic(cl,f[i],i);
	}
	if(cl==luo){
		if(jc(cl)){
			duanshu++;
		}
	}
	cout<< duanshu <<endl;
	return 0;
}
