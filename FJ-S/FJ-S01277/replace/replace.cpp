#include<bits/stdc++.h>
using namespace std;
map<string,string>mp;
struct node{
	int w;
	char a,b;
}ns[200005],nss[200005];
string s[200005],ss[200005],s1,s2;
int n,m,ans;
int main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	cin>>n>>m;
	
	if(n<=505){
		for(int i=1;i<=n;i++){
			cin>>s[i]>>ss[i];
			mp[s[i]]=ss[i];
		
		}
		for(int i=1;i<=m;i++){
		cin>>s1>>s2;
		ans=0;
		for(int j=1;j<=n;j++){
			if(s1.size()-s[j].size()+ss[j].size()!=s2.size()){
				continue;
			}
			if(s[j].size()>s1.size()){
				continue;
			}
			for(int k=0;k<s1.size();k++){
				if(s1[k]==s[j][0]){
					int f=1;
					for(int p=0;p<s[j].size();p++){
						if(s1[k+p]!=s[j][p]) {
							f=0;
						}
					} 
					if(f){
						string z;
						for(int q=0;q<k;q++){
							z+=s1[q];
						}
						for(int p=0;p<ss[j].size();p++){
							z+=ss[j][p];
						} 
						for(int p=k+s[j].size();p<s1.size();p++){
							z+=s1[p];
						} 
						if(z==s2){
							ans++;
						}
					}
				}
			}
			
		}
		cout<<ans<<endl;
	}
	}else{
		for(int i=1;i<=n;i++){
			cin>>s[i]>>ss[i];
			int cnt1=0,cnt2=0,w;
			char x='+',y='-';
			for(int j=0;j<s[i].size();j++){
				if(s[i][j]!=x and x>='a' and x<='z'){
					y=s[i][j];
				}else{
					x=s[i][j];
				}
				if(s[i][j]==x){
					cnt1++;
				}else{
					cnt2++;
				}
			}
			if(cnt2==1){
				ns[i].a=x;
				ns[i].b=y;
				for(int k=0;k<s[i].size();k++){
					if(s[i][k]==y){
						ns[i].w=k;
						break;
					}
				}
			}else{
				ns[i].a=y;
				ns[i].b=x;
				for(int k=0;k<s[i].size();k++){
					if(s[i][k]==x){
						ns[i].w=k;
						break;
					}
				}
			}
			int cnt3=0,cnt4=0;
			char xx='+',yy='-';
			for(int j=0;j<ss[i].size();j++){
				if(ss[i][j]!=xx and xx>='a' and xx<='z'){
					yy=ss[i][j];
				}else{
					xx=ss[i][j];
				}
				if(ss[i][j]==xx){
					cnt3++;
				}else{
					cnt4++;
				}
			}
			if(cnt4==1){
				nss[i].a=xx;
				nss[i].b=yy;
				for(int k=0;k<ss[i].size();k++){
					if(ss[i][k]==yy){
						nss[i].w=k;
						break;
					}
				}
			}else{
				nss[i].a=yy;
				nss[i].b=xx;
				for(int k=0;k<ss[i].size();k++){
					if(ss[i][k]==xx){
						nss[i].w=k;
						break;
					}
				}
			}
			
		}
		for(int i=1;i<=m;i++){
			cin>>s1>>s2;
			int w1,w2,cnt1=0,cnt2=0;
			char a1='-',b1='+',a2='-',b2='+',x='+',y='-';
			for(int j=0;j<s1.size();j++){
				if(s1[j]!=x and x>='a' and x<='z'){
					y=s1[j];
				}else{
					x=s1[j];
				}
				if(s1[j]==x){
					cnt1++;
				}else{
					cnt2++;
				}
			}
			if(cnt2==1){
				a1=x;
				b1=y;
				for(int k=0;k<s1.size();k++){
					if(s1[k]==y){
						w1=k;
						break;
					}
				}
			}else{
				a1=y;
				b1=x;
				for(int k=0;k<s1.size();k++){
					if(s1[k]==x){
						w1=k;
						break;
					}
				}
			}
			
			x='+',y='-';
			cnt1=cnt2=0;
			for(int j=0;j<s2.size();j++){
				if(s2[j]!=x and x>='a' and x<='z'){
					y=s2[j];
				}else{
					x=s2[j];
				}
				if(s2[j]==x){
					cnt1++;
				}else{
					cnt2++;
				}
			}
			if(cnt2==1){
				a2=x;
				b2=y;
				for(int k=0;k<s2.size();k++){
					if(s2[k]==y){
						w2=k;
						break;
					}
				}
			}else{
				a2=y;
				b2=x;
				for(int k=0;k<s2.size();k++){
					if(s2[k]==x){
						w2=k;
						break;
					}
				}
			}
			//cout<<w2<<endl;
			for(int j=1;j<=n;j++){
				if(s1.size()-s[j].size()+ss[j].size()!=s2.size()){
					continue;
				}
			//	cout<<ns[j].a<<" "<<ns[j].w<<" "<<ns[j].b<<endl;
			//	cout<<nss[j].a<<" "<<nss[j].w<<" "<<nss[j].b<<endl;
		//	cout<<endl<<ss[j].size()-nss[j].w<<" "<<s2.size()-w2<<endl;
				if(s[j].size()>2 and s1.size()>2){
					if(ns[j].a==a1 and ns[j].b==b1 and ns[j].w<=w1 and s[j].size()-ns[j].w<=s1.size()-w1){
						if(ss[j].size()>2){
							if(nss[j].a==a2 and nss[j].b==b2 and nss[j].w<=w2 and ss[j].size()-nss[j].w<=s2.size()-w2){
								ans++;
							}
						}else{
							if(nss[j].a!=a2 and ss[j].size()==2){
								swap(nss[j].a,nss[j].b);
								nss[j].w=ss[j].size()-nss[j].w;
							}else if(nss[j].a!=a2){
								swap(a2,b2);
								w2=s1.size()-w2;
							}
							if(nss[j].a==a2 and nss[j].b==b2 and nss[j].w<=w2 and ss[j].size()-nss[j].w<=s2.size()-w2){
								ans++;
							}
						}	
					}
				}else{
					if(ns[j].a!=a1 and s[j].size()==2){
						swap(ns[j].a,ns[j].b);
						ns[j].w=s[j].size()-ns[j].w;
					}else if(ns[j].a!=a1){
						swap(a1,b1);
						w1=s1.size()-w1;
					}
					if(ns[j].a==a1 and ns[j].b==b1 and ns[j].w<=w1 and s[j].size()-ns[j].w<=s1.size()-w1){
						if(ss[j].size()>2){
							if(nss[j].a==a2 and nss[j].b==b2 and nss[j].w<=w2 and ss[j].size()-nss[j].w<=s2.size()-w2){
								ans++;
							}
						}else{
							if(nss[j].a!=a2 and ss[j].size()==2){
								swap(nss[j].a,nss[j].b);
								nss[j].w=ss[j].size()-nss[j].w;
							}else if(nss[j].a!=a2){
								swap(a2,b2);
								w2=s1.size()-w2;
							}
							if(nss[j].a==a2 and nss[j].b==b2 and nss[j].w<=w2 and ss[j].size()-nss[j].w<=s2.size()-w2){
								ans++;
							}
						}
					}
				}
			}
			cout<<ans<<endl;
			ans=0;
			//cout<<a1<<" "<<a2<<" "<<b1<<" "<<b2<<" "<<w1<<" "<<w2<<endl;
		}
		
		
	}
	
	return 0;
}
