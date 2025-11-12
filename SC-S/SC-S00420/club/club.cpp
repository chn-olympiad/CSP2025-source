#include<bits/stdc++.h>
#define ll long long
using namespace std;
int t,n;
int a[100005][3];
bool cmp(int a,int b){
	return a>b;
}
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>t;
	while(t--){
		bool is_A=1,is_B=1;
		cin>>n;
		for(int i=1;i<=n;++i){
			cin>>a[i][1]>>a[i][2]>>a[i][3];
			if(a[i][2]!=0 || a[i][3]!=0){
				is_A=0;
				if(a[i][0]!=0) is_B=0;
			}
		}
		if(is_A){
			int* f=new int[n+5];
			for(int i=1;i<=n;++i){
				f[i]=a[i][1];
			}
			sort(f+1,f+n+1,cmp);
			int sum=0;
			for(int i=1;i<=n/2;++i){
				sum+=f[i];
			}
			cout<<sum<<endl;
		}
		else{
			int maxn=-1,cnt,xx;
			string s;
			for(int num=1;num<=pow(3,n);++num){
				cnt=0;
				s="";
				xx=num;
				while(xx){
					s=char((xx%3)+int('0'))+s;
					xx/=3;
				}
				while(s.size()<n) s='0'+s;
				int len=s.size();
				int cnt_0=0,cnt_1=0,cnt_2=0;
				for(int i=0;i<len;++i){
					if(s[i]=='0') cnt_0++;
					if(s[i]=='1') cnt_1++;
					if(s[i]=='2') cnt_2++;
				}
				if(cnt_0>n/2 || cnt_1>n/2 || cnt_2>n/2) continue;
				for(int i=0;i<len;++i){
					cnt+=a[i+1][s[i]-'0'+1];
				}
				maxn=max(maxn,cnt);
			}
			cout<<maxn<<endl;
		}
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
} 