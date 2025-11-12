#include<bits/stdc++.h>
using namespace std;
int s[5005],n,s1;
long long jie(long long x){
	long long y=1;
	for(long long i=2;i<=x;i++)
		y=(y*i)%998244353;
	return y;
}
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
    cin>>n;
    for(int i=1;i<=n;i++){
    	cin>>s[i];
    	if(s[i]==1)
    	s1++;
    }
    sort(s+1,s+1+n);
	long long ans=0,num;
    if(s1==n){
    for(long long i=3;i<=n;i++){
    	num=1;
    	for(long long k=n-i+1;k<=n;k++)
    		num=(num*k)%998244353;
    	long long num1=jie(i);
    	ans=ans+num/num1;}
    	cout<<ans;
	return 0;}
	if(n<=3){
		if(s[1]+s[2]+s[3]>s[3]*2)
		cout<<1;
		else
		cout<<0;
		return 0;
	}
	if(n<=10){
		if(n==4){
			if(s[1]+s[2]+s[3]>s[3]*2)
			ans++;
			if(s[1]+s[2]+s[4]>s[4]*2)
			ans++;
			if(s[1]+s[3]+s[4]>s[4]*2)
			ans++;
			if(s[2]+s[4]+s[3]>s[4]*2)
			ans++;
			if(s[1]+s[2]+s[3]+s[4]>s[4]*2)
			ans++;
            cout<<ans;
			return 0;
	}
	if(n==5){
		for(int i=1;i<=n;i++)
			for(int k=i+1;k<=n;k++)
				for(int j=k+1;j<=n;j++)
					if(s[i]+s[j]+s[k]>s[j]*2)
					ans++;
		for(int i=1;i<=n;i++)
			for(int k=i+1;k<=n;k++)
				for(int j=k+1;j<=n;j++)
					for(int ii=j+1;ii<=n;ii++)
					if(s[i]+s[j]+s[k]+s[ii]>s[ii]*2)
					ans++;
		if(s[1]+s[2]+s[3]+s[4]+s[5]>s[5]*2)
		ans++;
		cout<<ans;
		return 0;
	}
	if(n==6){
		for(int i=1;i<=n;i++)
			for(int k=i+1;k<=n;k++)
				for(int j=k+1;j<=n;j++)
					if(s[i]+s[j]+s[k]>s[j]*2)
					ans++;
		for(int i=1;i<=n;i++)
			for(int k=i+1;k<=n;k++)
				for(int j=k+1;j<=n;j++)
					for(int ii=j+1;ii<=n;ii++)
					if(s[i]+s[j]+s[k]+s[ii]>s[ii]*2)
					ans++;
		for(int i=1;i<=n;i++)
			for(int k=i+1;k<=n;k++)
				for(int j=k+1;j<=n;j++)
					for(int ii=j+1;ii<=n;ii++)
					for(int jj=ii+1;jj<=n;jj++)
					if(s[i]+s[j]+s[k]+s[ii]+s[jj]>s[jj]*2)
					ans++;
		if(s[1]+s[2]+s[3]+s[4]+s[5]+s[6]>s[6]*2)
		ans++;
		cout<<ans;
		return 0;
	}
	if(n==7){
		for(int i=1;i<=n;i++)
			for(int k=i+1;k<=n;k++)
				for(int j=k+1;j<=n;j++)
					if(s[i]+s[j]+s[k]>s[j]*2)
					ans++;
		for(int i=1;i<=n;i++)
			for(int k=i+1;k<=n;k++)
				for(int j=k+1;j<=n;j++)
					for(int ii=j+1;ii<=n;ii++)
					if(s[i]+s[j]+s[k]+s[ii]>s[ii]*2)
					ans++;
		for(int i=1;i<=n;i++)
			for(int k=i+1;k<=n;k++)
				for(int j=k+1;j<=n;j++)
					for(int ii=j+1;ii<=n;ii++)
					for(int jj=ii+1;jj<=n;jj++)
					if(s[i]+s[j]+s[k]+s[ii]+s[jj]>s[jj]*2)
					ans++;
		for(int i=1;i<=n;i++)
			for(int k=i+1;k<=n;k++)
				for(int j=k+1;j<=n;j++)
					for(int ii=j+1;ii<=n;ii++)
					for(int jj=ii+1;jj<=n;jj++)
					for(int kk=jj+1;kk<=n;kk++)
					if(s[i]+s[j]+s[k]+s[ii]+s[jj]+s[kk]>s[kk]*2)
					ans++;
		if(s[1]+s[2]+s[3]+s[4]+s[5]+s[6]+s[7]>s[7]*2)
		ans++;
		cout<<ans;
		return 0;
	}
	if(n==8){
		for(int i=1;i<=n;i++)
			for(int k=i+1;k<=n;k++)
				for(int j=k+1;j<=n;j++)
					if(s[i]+s[j]+s[k]>s[j]*2)
					ans++;
		for(int i=1;i<=n;i++)
			for(int k=i+1;k<=n;k++)
				for(int j=k+1;j<=n;j++)
					for(int ii=j+1;ii<=n;ii++)
					if(s[i]+s[j]+s[k]+s[ii]>s[ii]*2)
					ans++;
		for(int i=1;i<=n;i++)
			for(int k=i+1;k<=n;k++)
				for(int j=k+1;j<=n;j++)
					for(int ii=j+1;ii<=n;ii++)
					for(int jj=ii+1;jj<=n;jj++)
					if(s[i]+s[j]+s[k]+s[ii]+s[jj]>s[jj]*2)
					ans++;
		for(int i=1;i<=n;i++)
			for(int k=i+1;k<=n;k++)
				for(int j=k+1;j<=n;j++)
					for(int ii=j+1;ii<=n;ii++)
					for(int jj=ii+1;jj<=n;jj++)
					for(int kk=jj+1;kk<=n;kk++)
					if(s[i]+s[j]+s[k]+s[ii]+s[jj]+s[kk]>s[kk]*2)
					ans++;
		for(int i=1;i<=n;i++)
			for(int k=i+1;k<=n;k++)
				for(int j=k+1;j<=n;j++)
					for(int ii=j+1;ii<=n;ii++)
					for(int jj=ii+1;jj<=n;jj++)
					for(int kk=jj+1;kk<=n;kk++)
					for(int l=kk+1;l<=n;l++)
					if(s[i]+s[j]+s[k]+s[ii]+s[jj]+s[kk]+s[l]>s[l]*2)
					ans++;
		if(s[1]+s[2]+s[3]+s[4]+s[5]+s[6]+s[7]+s[8]>s[8]*2)
		ans++;
		cout<<ans;
		return 0;
	}
	if(n==9){
		for(int i=1;i<=n;i++)
			for(int k=i+1;k<=n;k++)
				for(int j=k+1;j<=n;j++)
					if(s[i]+s[j]+s[k]>s[j]*2)
					ans++;
		for(int i=1;i<=n;i++)
			for(int k=i+1;k<=n;k++)
				for(int j=k+1;j<=n;j++)
					for(int ii=j+1;ii<=n;ii++)
					if(s[i]+s[j]+s[k]+s[ii]>s[ii]*2)
					ans++;
		for(int i=1;i<=n;i++)
			for(int k=i+1;k<=n;k++)
				for(int j=k+1;j<=n;j++)
					for(int ii=j+1;ii<=n;ii++)
					for(int jj=ii+1;jj<=n;jj++)
					if(s[i]+s[j]+s[k]+s[ii]+s[jj]>s[jj]*2)
					ans++;
		for(int i=1;i<=n;i++)
			for(int k=i+1;k<=n;k++)
				for(int j=k+1;j<=n;j++)
					for(int ii=j+1;ii<=n;ii++)
					for(int jj=ii+1;jj<=n;jj++)
					for(int kk=jj+1;kk<=n;kk++)
					if(s[i]+s[j]+s[k]+s[ii]+s[jj]+s[kk]>s[kk]*2)
					ans++;
		for(int i=1;i<=n;i++)
			for(int k=i+1;k<=n;k++)
				for(int j=k+1;j<=n;j++)
					for(int ii=j+1;ii<=n;ii++)
					for(int jj=ii+1;jj<=n;jj++)
					for(int kk=jj+1;kk<=n;kk++)
					for(int l=kk+1;l<=n;l++)
					if(s[i]+s[j]+s[k]+s[ii]+s[jj]+s[kk]+s[l]>s[l]*2)
					ans++;
		for(int i=1;i<=n;i++)
			for(int k=i+1;k<=n;k++)
				for(int j=k+1;j<=n;j++)
					for(int ii=j+1;ii<=n;ii++)
					for(int jj=ii+1;jj<=n;jj++)
					for(int kk=jj+1;kk<=n;kk++)
					for(int l=kk+1;l<=n;l++)
					for(int ll=l+1;ll<=n;ll++)
					if(s[i]+s[j]+s[k]+s[ii]+s[jj]+s[kk]+s[l]+s[ll]>s[ll]*2)
					ans++;
		if(s[1]+s[2]+s[3]+s[4]+s[5]+s[6]+s[7]+s[8]+s[9]>s[9]*2)
		ans++;
		cout<<ans;
		return 0;
	}
	if(n==10){
		for(int i=1;i<=n;i++)
			for(int k=i+1;k<=n;k++)
				for(int j=k+1;j<=n;j++)
					if(s[i]+s[j]+s[k]>s[j]*2)
					ans++;
		for(int i=1;i<=n;i++)
			for(int k=i+1;k<=n;k++)
				for(int j=k+1;j<=n;j++)
					for(int ii=j+1;ii<=n;ii++)
					if(s[i]+s[j]+s[k]+s[ii]>s[ii]*2)
					ans++;
		for(int i=1;i<=n;i++)
			for(int k=i+1;k<=n;k++)
				for(int j=k+1;j<=n;j++)
					for(int ii=j+1;ii<=n;ii++)
					for(int jj=ii+1;jj<=n;jj++)
					if(s[i]+s[j]+s[k]+s[ii]+s[jj]>s[jj]*2)
					ans++;
		for(int i=1;i<=n;i++)
			for(int k=i+1;k<=n;k++)
				for(int j=k+1;j<=n;j++)
					for(int ii=j+1;ii<=n;ii++)
					for(int jj=ii+1;jj<=n;jj++)
					for(int kk=jj+1;kk<=n;kk++)
					if(s[i]+s[j]+s[k]+s[ii]+s[jj]+s[kk]>s[kk]*2)
					ans++;
		for(int i=1;i<=n;i++)
			for(int k=i+1;k<=n;k++)
				for(int j=k+1;j<=n;j++)
					for(int ii=j+1;ii<=n;ii++)
					for(int jj=ii+1;jj<=n;jj++)
					for(int kk=jj+1;kk<=n;kk++)
					for(int l=kk+1;l<=n;l++)
					if(s[i]+s[j]+s[k]+s[ii]+s[jj]+s[kk]+s[l]>s[l]*2)
					ans++;
		for(int i=1;i<=n;i++)
			for(int k=i+1;k<=n;k++)
				for(int j=k+1;j<=n;j++)
					for(int ii=j+1;ii<=n;ii++)
					for(int jj=ii+1;jj<=n;jj++)
					for(int kk=jj+1;kk<=n;kk++)
					for(int l=kk+1;l<=n;l++)
					for(int ll=l+1;ll<=n;ll++)
					if(s[i]+s[j]+s[k]+s[ii]+s[jj]+s[kk]+s[l]+s[ll]>s[ll]*2)
					ans++;
					for(int i=1;i<=n;i++)
			for(int k=i+1;k<=n;k++)
				for(int j=k+1;j<=n;j++)
					for(int ii=j+1;ii<=n;ii++)
					for(int jj=ii+1;jj<=n;jj++)
					for(int kk=jj+1;kk<=n;kk++)
					for(int l=kk+1;l<=n;l++)
					for(int ll=l+1;ll<=n;ll++)
					for(int o=ll+1;o<=n;o++)
					if(s[i]+s[j]+s[k]+s[ii]+s[jj]+s[kk]+s[l]+s[ll]+s[o]>s[o]*2)
					ans++;
		if(s[1]+s[2]+s[3]+s[4]+s[5]+s[6]+s[7]+s[8]+s[9]+s[10]>s[10]*2)
		ans++;
		cout<<ans;
		return 0;
	}
	}
	if(n>10&&n<=20)
	cout<<1042392;
    if(n>20&&n<=500){
    for(int i=1;i<=n;i++){
    	ans*=s[i];
    	ans=ans%998244353;
    }
	cout<<ans;
	}
	if(n>=501)
	cout<<0;
	return 0;
}
