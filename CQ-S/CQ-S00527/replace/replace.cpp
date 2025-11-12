#include<bits/stdc++.h>
using namespace std;
int n,q,Bsk1,Bsk2,ans,pr[200005],lns[200005],l[200005],r[200005],tl,tr,lnt[200005];
string ks1,ks2,s1[200005],s2[200005],t1[200005],t2[200005];
char *ic,*oc,ibuf[20000005],obuf[105],tbuf[15];
bool B,Bk;
int len;
void read(int &x){
	x=0;
	while(*ic<'0'||*ic>'9')ic++;
	while(*ic>='0'&&*ic<='9')x=x*10+(*ic++-'0');
}
void read(string &x){
	x="";
	while(*ic<'a'||*ic>'z')ic++;
	while(*ic>='a'&&*ic<='z')x.push_back(*ic++);
}
void write(int x){
	len=0;
	do{
		tbuf[++len]=x%10+48;
		x/=10;
	}while(x);
	for(int i=len;i>0;i--){
		*oc++=tbuf[i];
	}
}
vector<int> tmp;
map<pair<string,string>,vector<int>> mp;
int main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	fread(ibuf,1,20000000,stdin);
	ic=ibuf;oc=obuf;
	read(n);read(q);
	for(int i=1;i<=n;i++){
		read(s1[i]);read(s2[i]);
		if(s1[i]==s2[i]){
			i--;n--;continue;
		}
		lns[i]=s1[i].size();
		Bk=1;Bsk1=Bsk2=0;
		for(int j=0;j<lns[i];j++){
			Bk&=(s1[i][j]=='a'||s1[i][j]=='b');
			Bk&=(s2[i][j]=='a'||s2[i][j]=='b');
			Bsk1+=(s1[i][j]=='b');
			Bsk2+=(s2[i][j]=='b');
		}
		Bk&=(Bsk1==1&&Bsk2==1);
	}
	for(int i=1;i<=q;i++){
		read(t1[i]);read(t2[i]);
		if(t1[i].size()!=t2[i].size())continue;
		lnt[i]=t1[i].size();
		Bk=1;Bsk1=Bsk2=0;
		for(int j=0;j<lnt[i];j++){
			Bk&=(t1[i][j]=='a'||t1[i][j]=='b');
			Bk&=(t2[i][j]=='a'||t2[i][j]=='b');
			Bsk1+=(t1[i][j]=='b');
			Bsk2+=(t2[i][j]=='b');
		}
		Bk&=(Bsk1==1&&Bsk2==1);
	}
	if(Bk){
		for(int i=1;i<=n;i++){
			ks1=ks2="";
			for(int j=0;j<lns[i];j++){
				if(s1[i][j]!=s2[i][j]){
					l[i]=j;break;
				}
			}
			for(int j=lns[i]-1;j>=0;j--){
				if(s1[i][j]!=s2[i][j]){
					r[i]=j;break;
				}
			}
			for(int j=l[i];j<=r[i];j++){
				ks1.push_back(s1[i][j]);
				ks2.push_back(s2[i][j]);
			}
			mp[{ks1,ks2}].push_back(i);
		}
		for(int i=1;i<=q;i++){
			if(t1[i].size()!=t2[i].size()){
				*oc++='0';*oc++='\n';
				continue;
			}
			ans=0;
			ks1=ks2="";
			lnt[i]=t1[i].size();
			for(int j=0;j<lnt[i];j++){
				if(t1[i][j]!=t2[i][j]){
					tl=j;break;
				}
			}
			for(int j=lnt[i]-1;j>=0;j--){
				if(t1[i][j]!=t2[i][j]){
					tr=j;break;
				}
			}
			for(int j=tl;j<=tr;j++){
				ks1.push_back(t1[i][j]);
				ks2.push_back(t2[i][j]);
			}
			tmp=mp[{ks1,ks2}];
			if(tmp.size()==0){
				*oc++='0';*oc++='\n';
				continue;
			}
			for(int k=0;k<tmp.size();k++){
				if(tl>=l[tmp[k]]&&lns[tmp[k]]-1-l[tmp[k]]+tl<lnt[i])ans++;
			}
			write(ans);*oc++='\n';
		}
		fwrite(obuf,1,oc-obuf,stdout);
		return 0;
	}
	for(int i=1;i<=n;i++){
		ks1=ks2="";
		for(int j=0;j<lns[i];j++){
			if(s1[i][j]!=s2[i][j]){
				l[i]=j;break;
			}
		}
		for(int j=lns[i]-1;j>=0;j--){
			if(s1[i][j]!=s2[i][j]){
				r[i]=j;break;
			}
		}
		for(int j=l[i];j<=r[i];j++){
			ks1.push_back(s1[i][j]);
			ks2.push_back(s2[i][j]);
		}
		mp[{ks1,ks2}].push_back(i);
	}
	for(int i=1;i<=q;i++){
		if(t1[i].size()!=t2[i].size()){
			*oc++='0';*oc++='\n';
			continue;
		}
		ans=0;
		ks1=ks2="";
		lnt[i]=t1[i].size();
		for(int j=0;j<lnt[i];j++){
			if(t1[i][j]!=t2[i][j]){
				tl=j;break;
			}
		}
		for(int j=lnt[i]-1;j>=0;j--){
			if(t1[i][j]!=t2[i][j]){
				tr=j;break;
			}
		}
		for(int j=tl;j<=tr;j++){
			ks1.push_back(t1[i][j]);
			ks2.push_back(t2[i][j]);
		}
		tmp=mp[{ks1,ks2}];
		if(tmp.size()==0){
			*oc++='0';*oc++='\n';
			continue;
		}
		for(int k=0;k<tmp.size();k++){
			if(tl<l[tmp[k]])continue;
			B=1;
			for(int j=0;j<lns[tmp[k]];j++){
				if(j-l[tmp[k]]+tl>=lnt[i]||s1[tmp[k]][j]!=t1[i][j-l[tmp[k]]+tl]){
					B=0;break;
				}
			}
			ans+=B;
		}
		write(ans);*oc++='\n';
	}
	fwrite(obuf,1,oc-obuf,stdout);
	return 0;
}
