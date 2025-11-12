#include<bits/stdc++.h>
using namespace std;
const int N=1e6+10;
int n,q,ans,l;
int cnt1,cnt2,f,t1,t2,n1,n2,k;
int zm1[26],zm2[26];
string st,ed;
struct node{
	string st,ed;
	int zm1[26],zm2[26];
}a[N];
string x,y,z;
int mp[26][26][26][26];
int main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	cin>>n>>q;
	f=1;
	for(int i=1;i<=n;i++){
		cin>>a[i].st>>a[i].ed;
		l+=a[i].st.size()*2;
		cnt1=cnt2=0,t1=t2=n1=n2=26;
		for(int j=0;j<a[i].st.size();j++){
			k=a[i].st[j]-'a';
			if(a[i].zm1[k]==0) cnt1++;
			a[i].zm1[k]++;
			if(t1==26||t1==k) t1=k;
			else n1=k;
			
			k=a[i].ed[j]-'a';
			if(a[i].zm2[k]==0) cnt2++;
			a[i].zm2[k]++;
			if(t2==26||t2==k) t2=k;
			else n2=k;
		}
		if(cnt1>2||cnt2>2) f=0;
		else{
			if(a[i].zm1[t1]>a[i].zm1[n1]) swap(t1,n1);
			if(a[i].zm2[t2]>a[i].zm2[n2]) swap(t2,n2);
			mp[t1][n1][t2][n2]++;
		} 
	}
	while(q--){
		cin>>st>>ed;
		if(st.size()!=ed.size()){
			cout<<"0\n";
			continue;
		}
		cnt1=cnt2=0,t1=t2=n1=n2=26;
		for(int i=0;i<st.size();i++){
			k=st[i]-'a';
			if(zm1[k]==0) cnt1++;
			zm1[k]++;
			if(t1==26||t1==k) t1=k;
			else n1=k;
			
			k=ed[i]-'a';
			if(zm2[k]==0) cnt2++;
			zm2[k]++;
			if(t2==26||t2==k) t2=k;
			else n2=k;
		}
		if(f==1&&cnt1<=2&&cnt2<=2&&l>2000){
			if(zm1[t1]>zm1[n1]) swap(t1,n1);
			if(zm2[t2]>zm2[n2]) swap(t2,n2);
			cout<<mp[t1][n1][t2][n2]<<endl;
			zm1[t1]=zm1[n1]=zm2[t2]=zm2[n2]=0;
		}else{
			ans=0;
			x=y=z="";
			for(int i=0;i<=st.size();i++){
				for(int j=1;j<=n;j++){
					if(i+a[j].st.size()-1>=st.size()) continue;
					y=st.substr(i,a[j].st.size());
					if(y!=a[j].st) continue;
					z=st.substr(i+a[j].st.size(),st.size()-(i+a[j].st.size()));
					if(x+a[j].ed+z==ed) ans++;
				} 
				x=x+st[i];
			}
			cout<<ans<<endl;
		}
	}
	return 0;
}
