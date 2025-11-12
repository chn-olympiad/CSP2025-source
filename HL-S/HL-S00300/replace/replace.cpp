#include <bits/stdc++.h>
using namespace std;
int n,q,net[200100],ans;
string sa[200100],sb[200100],ta[200100],tb[200100],test,testt;
bool flag,flagw;
void build_next(string arr){
	int tlong=0,tt=1;
	memset(net,0,sizeof(net));
	for(int i=1;i<arr.length();i++){
		if(arr[i]==arr[tlong]){
			net[i]=tt;
			tlong++,tt++;
		}
		else tlong=0,tt=1;
	}
}
void kmp(string a,int ah,string b,int bh){
	int tl=0,tmax=a.length();
	for(int i=0;i<b.length();i++){
		if(tl==tmax){
			flag=true;
			for(int j=0;j<i-tl;j++){
				if(b[j]!=tb[bh][j]) {
					flag=false;
					break;
				}
			}
			if(flag){
				for(int j=i-tl;j<i;j++){
					if(sb[ah][j-(i-tl)]!=tb[bh][j]){
						flag=false;
						break;
					}
				}
				if(flag){
					for(int j=i;j<b.length();j++){
						if(b[j]!=tb[bh][j]){
							flag=false;
							break;
						}
					}
				}
			}
			if(flag) ans++;
		}
		if(b[i]==a[tl]) tl++;	
		else{
			i=i-tl+net[tl];
			tl=0;
		}
	}
}
int main(){
	cin.tie(0);
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	cin >> n >> q;
	for(int i=1;i<=n;i++) cin >> sa[i]>>sb[i];
	for(int i=1;i<=q;i++) cin >> ta[i]>>tb[i];
	for(int i=1;i<=q;i++){
		if(ta[i].length()!=tb[i].length()){
			cout << "0"<<endl;
			continue;
		}
		ans=0;
		for(int j=1;j<=n;j++){
			if(sa[j].length()>ta[i].length()) continue;
			if(sa[j]==ta[i]&&sb[j]==tb[i]) ans++;
			build_next(sa[j]);
			kmp(sa[j],j,ta[i],i);
		}
		cout << ans<<endl;
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}