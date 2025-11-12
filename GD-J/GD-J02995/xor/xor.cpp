#include <bits/stdc++.h>
using namespace std;
int l,r;
int n,k;
string sum;

struct X{
	int b,e,ch;
}v[50025];

bool cmp(X i,X j){
	if(i.ch!=j.ch){
		return i.ch<j.ch; 
	}else{
		return i.b<j.b;
	}
}

string zhuan(long long n1){
	string s1,s2;
	while(n1){
		s1+=n1%2+'0';
		n1/=2;
	}
	for(int j=s1.size()-1;j>=0;j--){
		s2+=s1[j];
	}
	return s2;
}

string nxor(string s[]){
	sum=s[l];
	for(int i=l+1;i<=r;i++){
		string sum1,sum2;
		int kkk=sum.size();
		int kk=s[i].size();
		int xx=max(kkk,kk);
		int xxx=min(kkk,kk);
		for(int j=0;j<xx;j++){
			if(j<xxx){
				if(sum[i]=='0'&&s[i][j]=='1'||sum[i]=='1'&&s[i][j]=='0'){
					sum1+='1';
				}else{
					sum1+='0';
				}
			}else if(sum.size()>s[i].size()){
				sum1+=sum[i];
			}else{
				sum1+=s[i][j];
			}
		}
		for(int j=sum1.size()-1;j>=0;j--){
			sum2+=sum1[j];
		}
		sum=sum2;
	}
	return sum;
}

bool panduan(bool flag[],int g){cout<<v[g].b<<" "<<v[g].e<<" ";
	for(int dd=v[g].b;dd<=v[g].e;dd++){
		if(flag[dd]==1){
			return 0;
		}
	}
	
	return 1;
}

void biaoji(bool flag[],int g){
	for(int dd=v[g].b;dd<=v[g].e;dd++){
		flag[dd]=1;
	}
}
int main(){
	//freopen("xor.in","r",stdin);
	//freopen("xor.out","w",stdout);
	int summm=0;
	cin>>n>>k;
	string s[n+5],ks=zhuan(k);
	long long a[n+5];
	for(int i=0;i<n;i++){
		cin>>a[i];
		s[i]=zhuan(a[i]);
	}
	int i=0;
	for(l=0;l<n;l++){
		for(r=l;r<n;r++){
			if(nxor(s)==ks){
				v[i].b=l;
				v[i].e=r;
				v[i].ch=r-l+1;
				cout<<l<<" "<<r<<" "<<r-l+1<<endl;
				i++;
			}
		}
	}
	sort(v,v+i,cmp);
	bool flag[n];
	for(int g=0;g<i;){
		if(panduan(flag,g)){
			biaoji(flag,g);
			summm++;
		}g++;
	}
	cout<<summm+1;
	return 0;
}
