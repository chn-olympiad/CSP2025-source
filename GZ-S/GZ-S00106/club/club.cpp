//GZ-S00106 贵州师范大学云岩实验中学 周文钊
#include<bits/stdc++.h>
using namespace std;
long long n;
long long q[3][1000011];
long long f[3][1000111],se[3][1000011],th[3][1000011];
long long flag[3][100011] = {0};
long long dp(long long s){
	long long a,b,c,ans = 0;
	a=s/2;
	b=a;
	c=a;
	for(long long i = 0;i<s;i++){
		if(q[0][i]==q[1][i] and q[0][i]==q[2][i]){
			flag[0][i]=1;
			flag[1][i]=1;
			flag[2][i]=1;
		}
		else if(q[0][i]==q[1][i]and q[0][i]>q[2][i]){
			flag[0][i]=1;
			flag[1][i]=1;
			flag[2][i]=0;
		}
		else if(q[0][i]==q[2][i]and q[0][i]>q[1][i]){
			flag[0][i]=1;
			flag[1][i]=0;
			flag[2][i]=1;
		}
		else if(q[1][i]==q[2][i]and q[0][i]<q[2][i]){
			flag[0][i]=0;
			flag[1][i]=1;
			flag[2][i]=1;
		}
		else if(q[0][i]>q[1][i]and q[0][i]>q[2][i]){
			flag[0][i]=1;
			if(q[1][i]>q[2][i]){
				flag[1][i] = 0;
				flag[2][i] = -1;
			}
			else{
				flag[1][i] = -1;
				flag[2][i] = 0;
			}
		}
		else if(q[1][i]>q[2][i]and q[1][i]>q[0][i]){
			flag[1][i]=1;
			if(q[0][i]>q[2][i]){
				flag[0][i] = 0;
				flag[2][i] = -1;
			}
			else{
				flag[0][i] = -1;
				flag[2][i] = 0;
			}
		}
		else if(q[2][i]>q[1][i]and q[2][i]>q[0][i]){
			flag[2][i]=1;
			if(q[1][i]>q[0][i]){
				flag[1][i] = 0;
				flag[0][i] = -1;
			}
			else{
				flag[1][i] = -1;
				flag[0][i] = 0;
			}
		}
	}
	for(long long i = 0;i<s;i++){
		for(long long j = 0;j<3;j++){
			f[j][i] = abs(q[0][i]-q[j][i]);
			se[j][i] = abs(q[1][i]-q[j][i]);
			th[j][i] = abs(q[2][i]-q[j][i]); 
		}
	}
	for(long long i = 0;i<s;i++){
		for(long long j = 0;j<3;j++){
			if(flag[j][i]==1){
				ans+=q[j][i];
				if(j==0){
					a--;
				}
				else if(j==1){
					b--;
				}
				else{
					c--;
				}
			}
		}
	}
	if(a<0){
		long long ca[100011];
		string z[100011];
		for(long long i = 0;i<s;i++){
			if(f[1][i]>f[2][i]){
				ca[i] = f[2][i];
				z[i] = "c";
			}
			else if(f[1][i]==f[2][i]){
				ca[i]=f[1][i];
				z[i] = "s";
			}
			else{
				ca[i] = f[1][i];
				z[i] = "b";
			}
		}
		while(a<0){
			long long man = 200000002,k = 0;
			for(int i = 0;i<s;i++){
				if(ca[i]<man){
					man = ca[i];
					k = i;
				}
			}
			if(z[k]=="b" and b>0){
				ans-=ca[k];
				a++;
				b--;
			}
			else if(z[k]=="s" and b<=0){
				ans-=ca[k];
				a++;
				c--;
			}
			else if(z[k]=="s" and c<=0){
				ans-=ca[k];
				a++;
				b--;	
			}
			else{
				ans-=ca[k];
				a++;
				c--;
			}
			ca[k] = 2000000000;
		}
	}
	if(b<0){
		long long ca[100011];
		string z[10011];
		for(long long i = 0;i<s;i++){
			if(se[0][i]>se[2][i]){
				ca[i] = se[2][i];
				z[i] = "c";
			}
			else if(se[0][i]==se[2][i]){
				ca[i]=se[0][i];
				z[i] = "s";
			}
			else{
				ca[i] = se[0][i];
				z[i] = "a";
			}
		}
		while(b<0){
			int man = 200000002,k = 0;
			for(long long i = 0;i<s;i++){
				if(ca[i]<man){
					man = ca[i];
					k = i;
				}
			}
			if(z[k]=="c" and c>0){
				ans-=ca[k];
				b++;
				c--;
			}
			else if(z[k]=="s" and a<=0){
				ans-=ca[k];
				b++;
				c--;
			}
			else if(z[k]=="s" and c<=0){
				ans-=ca[k];
				b++;
				a--;	
			}
			else{
				ans-=ca[k];
				b++;
				a--;
			}
			ca[k] = 200000005;
		}
	}
	if(c<0){
		long long ca[100011];
		string z[100011];
		for(long long i = 0;i<s;i++){
			if(th[0][i]>th[1][i]){
				ca[i] = th[1][i];
				z[i] = "b";
			}
			else if(th[0][i]==th[1][i]){
				ca[i]=th[0][i];
				z[i] = "s";
			}
			else{
				ca[i] = th[0][i];
				z[i] = "a";
			}
		}
		while(b<0){
			int man = 200000000,k = 0;
			for(long long i = 0;i<s;i++){
				if(ca[i]<man){
					man = ca[i];
					k = i;
				}
			}
			if(z[k]=="a" and a>0){
				ans-=ca[k];
				c++;
				a--;
			}
			else if(z[k]=="s" and a<=0){
				ans-=ca[k];
				c++;
				b--;
			}
			else if(z[k]=="s" and b<=0){
				ans-=ca[k];
				c++;
				a--;	
			}
			else{
				ans-=ca[k];
				c++;
				b--;
			}
			ca[k] = 200000005;
		}
	}
	else{
		return ans;
	}
}
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>n;
	while(n--){
		long long m,x;
		cin>>m;
		x = m;
		for(int i = 0;i<x;i++){
			cin>>q[0][i]>>q[1][i]>>q[2][i];
		}
		cout<<dp(x)<<endl;
	}
	return 0;
} 
