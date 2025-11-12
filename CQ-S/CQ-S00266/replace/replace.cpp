#include<bits/stdc++.h>
using namespace std;
int n,q;
string s[200005][2],t[200005][2];
int ans[200005],wzs[200005][2],wzt[200005][2];
bool flag;
unsigned long long iop[200005],sums1[200005],sumt1[200005],sums2[200005],sumt2[200005];
unsigned long long gets1(unsigned long long l,unsigned long long r){
	return sums1[r]-iop[r-l+1]*sums1[l-1];
}
unsigned long long gets2(int l,int r){
	return sums2[r]-sums2[l-1]*iop[r-l+1];
}
unsigned long long gett1(int l,int r){
	return sumt1[r]-sumt1[l-1]*iop[r-l+1];
}
unsigned long long gett2(int l,int r){
	return sumt2[r]-sumt2[l-1]*iop[r-l+1];
}
int main()
{
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin>>n>>q;
	int sum=0;
	for (int i=1;i<=n;i++){
		cin>>s[i][0]>>s[i][1];
		sum+=s[i][0].length();
	}
	for (int i=1;i<=q;i++){
		cin>>t[i][0]>>t[i][1];
		sum+=t[i][0].length();
	}
	flag=1;
	for (int i=1;i<=n;i++){
		bool tag=0;
		for (auto j:s[i][0]){
			if (j!='a' && j!='b'){
				flag=0;
				break;
			}
			if (j=='b' && tag==1){
				flag=0;
				break;
			}
			else if (j=='b'){
				tag=1;
			}
		}
		if (!tag) flag=0;
		tag=0;
		for (auto j:s[i][1]){
			if (j!='a' && j!='b'){
				flag=0;
				break;
			}
			if (j=='b' && tag==1){
				flag=0;
				break;
			}
			else if (j=='b'){
				tag=1;
			}
		}
		if (!tag) flag=0;
	}
	for (int i=1;i<=q;i++){
		bool tag=0;
		for (auto j:t[i][0]){
			if (j!='a' && j!='b'){
				flag=0;
				break;
			}
			if (j=='b' && tag==1){
				flag=0;
				break;
			}
			else if (j=='b'){
				tag=1;
			}
		}
		if (!tag) flag=0;
		tag=0;
		for (auto j:t[i][1]){
			if (j!='a' && j!='b'){
				flag=0;
				break;
			}
			if (j=='b' && tag==1){
				flag=0;
				break;
			}
			else if (j=='b'){
				tag=1;
			}
		}
		if (!tag) flag=0;
	}
	if (1ll*n*sum<=100000000){
		for (int i=1;i<=n;i++){
			sums1[0]=0;
			iop[0]=1;
			for (int j=1;j<=s[i][0].length();j++){
				sums1[j]=sums1[j-1]*31+s[i][0][j-1]-'a';
				iop[j]=iop[j-1]*31;
			}
			
			sums2[0]=0;
			iop[0]=1;
			for (int j=1;j<=s[i][1].length();j++){
				sums2[j]=sums2[j-1]*31+s[i][1][j-1]-'a';
				iop[j]=iop[j-1]*31;
			}
			for (int j=1;j<=q;j++){
				sumt1[0]=0;
				iop[0]=1;
				for (int k=1;k<=t[j][0].length();k++){
					sumt1[k]=sumt1[k-1]*31+t[j][0][k-1]-'a';
					iop[k]=iop[k-1]*31;
				}
				sumt2[0]=0;
				iop[0]=1;
				for (int k=1;k<=t[j][1].length();k++){
					sumt2[k]=sumt2[k-1]*31+t[j][1][k-1]-'a';
					iop[k]=iop[k-1]*31;
				}
				int ls=s[i][0].length(),lt=t[j][0].length();
				for (int k=ls;k<=lt;k++){
					if (gets1(1,ls)==gett1(k-ls+1,k) && gets2(1,ls)==gett2(k-ls+1,k)){
						if (k!=ls && gett1(1,k-ls)!=gett2(1,k-ls)){
							continue;
						}
						if (k!=lt && gett1(k+1,lt)!=gett2(k+1,lt)){
							continue;
						}
						ans[j]++;
						break;
					}
				}
			}
		}
		for (int i=1;i<=q;i++){
			cout<<ans[i]<<"\n";
		}
	}
	else if (flag){
		for (int i=1;i<=n;i++){
			for (int j=0;j<s[i][0].length();j++){
				if (s[i][0][j]=='b'){
					wzs[i][0]=j;
				}
			}
			for (int j=0;j<s[i][1].length();j++){
				if (s[i][1][j]=='b'){
					wzs[i][1]=j;
				}
			}
		}
		for (int i=1;i<=q;i++){
			for (int j=0;j<t[i][0].length();j++){
				if (t[i][0][j]=='b'){
					wzt[i][0]=j;
				}
			}
			for (int j=0;j<t[i][1].length();j++){
				if (t[i][1][j]=='b'){
					wzt[i][1]=j;
				}
			}
		}
		for (int i=1;i<=q;i++){
			int ans=0;
			for (int j=1;j<=n;j++){
				if (wzs[j][0]-wzs[j][1]==wzt[j][0]-wzt[j][1] && wzs[j][0]<=wzt[i][0] && s[j][0].length()-wzs[j][0]<=t[i][0].length()-wzt[i][0]){
					ans++;
				}
			}
			cout<<ans<<"\n";
		}
	}
	else {
		cout<<0;
	}
}
