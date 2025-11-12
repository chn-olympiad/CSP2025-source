#include<bits/stdc++.h>
using namespace std;
const int N=2e5+5;
int n,q,lt,ltt,nw,ans,dt,tb,ttb,cb,ccb;
int ls[N],ok[N],d[N],rb[N],ssb[N];
string t,tt;
string s[N],ss[N];
bool check1(int x,int l,int r){
	for(int i=0; i<ls[x]; i++){
		if(s[x][i]!=t[l+i]) return 0;
	}
	return 1;
}
bool check2(int x,int l,int r){
	for(int i=0; i<ls[x]; i++){
		if(ss[x][i]!=tt[l+i]) return 0;
	}
	return 1;
}
bool checkB(){
	for(int i=1; i<=n; i++){
		int cnta=0,cntb=0;
		for(int j=0; j<ls[i]; j++){
			if(s[i][j]=='a') cnta++;
			if(s[i][j]=='b') cntb++;
		}
		if(cnta+cntb!=ls[i] || cntb!=1) return 0;
	}
	return 1;
} 
int main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	scanf("%d%d",&n,&q);
	for(int i=1; i<=n; i++){
		cin>>s[i]>>ss[i];
		ls[i]=s[i].length();
	}
	if(n<=1000 && !checkB()){
		while(q--){
			cin>>t>>tt;
			lt=t.length();
			ltt=tt.length();
			if(lt!=ltt){
				puts("0");
				continue;
			}
			for(int i=1; i<=lt; i++) ok[i]=0;
			ok[lt]=1;
			for(int i=lt-1; i>=0; i--){
				if(ok[i+1] && t[i]==tt[i]) ok[i]=1;
				else ok[i]=0;
			}
			nw=ans=0;
			for(int w=0; w<lt; w++){
				if(nw) break;
				for(int i=1; i<=n; i++){
					if(w+ls[i]-1>=lt) continue;
					if(!check1(i,w,w+ls[i]-1)) continue;
					if(!check2(i,w,w+ls[i]-1)) continue;
					if(ok[w+ls[i]]) ans++;
				}
				if(t[w]!=tt[w]) nw=1;
			}
			printf("%d\n",ans);
		}
	}
	else if(checkB()){
		for(int i=1; i<=n; i++){
			for(int j=0; j<ls[i]; j++){
				if(s[i][j]=='b'){
					cb=j;
					rb[i]=j;
					break;
				}
			}
			for(int j=0; j<ls[i]; j++){
				if(ss[i][j]=='b'){
					ccb=j;
					ssb[i]=j;
					break;
				}
			}
			d[i]=ccb-cb;
		}
		while(q--){
			cin>>t>>tt;
			lt=t.length();
			ltt=tt.length();
			if(lt!=ltt){
				puts("0");
				continue;
			}
			for(int i=0; i<lt; i++){
				if(t[i]=='b'){
					tb=i;
					break;
				}
			}
			for(int i=0; i<lt; i++){
				if(tt[i]=='b'){
					ttb=i;
					break; 
				}
			}
			dt=ttb-tb,ans=0;
			for(int i=1; i<=n; i++){
				if(dt!=d[i]) continue;
				if(ltt-ttb>=ls[i]-ssb[i] && lt-tb>=ls[i]-rb[i] && tb>=rb[i] && ttb>=ssb[i]) ans++;
			}
			printf("%d\n",ans);
		}
	}
	return 0;
}
