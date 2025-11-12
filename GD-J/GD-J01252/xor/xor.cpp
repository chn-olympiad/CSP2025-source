#include<bits/stdc++.h>
using namespace std;
long long n,k,sum;
int a[1005],a0=0,b[1005]={0};
int zhuan_wei_shi_jin_zhi(string s){
	int p=0;
	for(int i=1;i<s.size()+1;i++){
		p+=(pow(2,i)*((int)s[i]-48));
	}
	return p;
}
int zhuan_wei_er_jin_zhi(int a){
	string s;
	int p=0;
	while(a>0){
		p+=1;
		s[p]=((char)a%2+48);
		a/=2;
	}
	int l=0;
	for(int i=p;i>=1;i--){
		l=l*10+((int)s[i]-48);
	}
	return l;
}
int er_jin_zhi_bi_jiao(int ii,int jj){
	int b1[1005],f=0;
	string s3;
	for(int i=1;i<=n;i++){
		b1[i]=a[i];
	}
	for(int i=ii;i<=jj;i++){
		string s1,s2,s;
		int i1=a[i],i2=a[i+1],p1=0,p2=0;
		while(i1>0){
			p1+=1;
			s1[p1]=((char)i1%10+48);
			i1/=10;
		}
		while(i2>0){
			p2+=1;
			s2[p2]=((char)i2%10+48);
			i2/=10;
		}
		int i3=max(i1,i2);
		if(i1<i2){
			while(p1<p2){
				p1+=1;
				s1+='0';
			}
		}else if(i1>i2){
			while(p2<p1){
				p2+=1;
				s2+='0';
			}
		}
		for(int x=1;x<=i3;x++){
			if(s1[x]=='0'&&s2[x]=='1'){
				s[x]+='1';
			}else if(s1[x]=='1'&&s2[x]=='1'){
				s[x]+='1';
			}else if(s1[x]=='0'&&s2[x]=='0'){
				s[x]+='0';
			}else{
				s[x]+='1';
			}
		}
		if(i==jj-1){
			s3+=s;
		}
		a[i+1]=zhuan_wei_shi_jin_zhi(s);
		int v=zhuan_wei_er_jin_zhi(a[i+1]);
		a[i+1]=v;
	}
	//cout<<ii<<","<<jj<<":"<<a[jj]<<" "<<s3<<endl;
	a[jj]=zhuan_wei_shi_jin_zhi(s3);
	
	if(a[jj]==k){
		f=1;
	}
	for(int i=1;i<=n;i++){
		a[i]=b1[i];
	}
	if(f==1){
		return 1;
	}else{
		return 0;
	}
}

int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	int A=1,B=1,C=1;
	cin>>n>>k;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		if(a[i]!=1){
			A=0;
		}
		if(a[i]!=0&&a[i]!=1){
			B=0;
		}
		if(a[i]>255){
			C=0;
		}
		if(a[i]==0){
			a0+=1;
		}
	}
//	cout<<A<<" "<<B<<" "<<C<<endl;
	if(A==1){
		cout<<0;
		return 0;
	}else if(B==1){
		if(k==0){
			cout<<a0;
		}else{
			cout<<n-a0;
		}
		return 0;
	}else if(C==1){
		for(int i=1;i<=n;i++){
			int v=zhuan_wei_er_jin_zhi(a[i]);
			a[i]=v;
			//cout<<a[i]<<" ";
		}
		for(int i=1;i<=n;i++){
			for(int j=i;j<=n;j++){
				int f=er_jin_zhi_bi_jiao(i,j);
				if(f==1){
					int ff=0;
					for(int c=i;c<=j;c++){
						if(b[i]==1){
							ff=1;
							break;
						}
					}
					if(ff==0){
						for(int c=i;c<=j;c++){
							b[i]=1;
						}
						sum+=1;
					}
				}
			}
		}
	}
	cout<<sum;
	return 0;
}
/*

*/
