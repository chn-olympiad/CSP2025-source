#include<bits/stdc++.h>
using namespace std;
int n,q,len,l[200005],zuo,you,cd,ans,cj[200005],tmp,wz[200005];
string s[200005][2],t1,t2;
bool flag,f=true,ff;
int cou(char ch,string &ss){
	int num=0;
	for(auto x:ss)
		if(x==ch)
			num++;
	return num;
}
int main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>n>>q;
	for(int i=1;i<=n;i++){
		cin>>s[i][0]>>s[i][1];
		l[i]=s[i][0].size();
		tmp=cou('b',s[i][0]);
		if(f&&(cou('a',s[i][0])+tmp!=s[i][0].size()||tmp!=1))
			f=false;
		tmp=cou('b',s[i][1]);
		if(f&&(cou('a',s[i][1])+tmp!=s[i][1].size()||tmp!=1))
			f=false;
	}
	if(f){
		for(int i=1;i<=n;i++){
			for(int j=0;j<l[i];j++)
				if(s[i][0][j]=='b'){
					zuo=j;
					break;
				}
			for(int j=0;j<l[i];j++)
				if(s[i][1][j]=='b'){
					you=j;
					break;
				}
			cj[i]=zuo-you;
			wz[i]=zuo;
		}
	}
	while(q--){
		ans=0;
		cin>>t1>>t2;
		if(t1.size()!=t2.size()){
			cout<<'0'<<'\n';
			continue;
		}
		ff=true;
		len=t1.size();
		tmp=cou('b',t1);
		if(ff&&(cou('a',t1)+tmp!=len||tmp!=1))
			ff=false;
		tmp=cou('b',t2);
		if(ff&&(cou('a',t2)+tmp!=len||tmp!=1))
			ff=false;
		if(ff&&f){
			for(int j=0;j<len;j++)
				if(t1[j]=='b'){
					zuo=j;
					break;
				}
			for(int j=0;j<len;j++)
				if(t2[j]=='b'){
					you=j;
					break;
				}
			for(int i=1;i<=n;i++)
				if(cj[i]==zuo-you&&zuo>=wz[i]&&len-you>=l[i]-wz[i]+cj[i])
					ans++;
			cout<<ans<<'\n';
			continue;
		}
		for(int i=0;i<len;i++)
			if(t1[i]!=t2[i]){
				zuo=i;
				break;
			}
		for(int i=len-1;i>=0;i--)
			if(t1[i]!=t2[i]){
				you=i;
				break;
			}
		for(int i=1;i<=n;i++){
			cd=you-zuo+1;
			if(cd>l[i])
				continue;
			for(int j=max(0,you-l[i]+1),k=j+l[i]-1;j<=zuo&&k<len;j++,k++){
				flag=true;
				for(int tmp=j,tpm=0;tmp<=k;tmp++,tpm++)
					if(s[i][0][tpm]!=t1[tmp]||s[i][1][tpm]!=t2[tmp]){
						flag=false;
						break;
					}
				if(flag)
					ans++;
			}
		}
		cout<<ans<<'\n';
	}
	return 0;
}
