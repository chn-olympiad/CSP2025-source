#include<bits/stdc++.h>
using namespace std;
int n,q,ans;
string a[200010][3],t1,t2;
int find(string a1,string b){
	for (int i=0;i<a1.size();i++){
	bool t=true;
	for (int j=0;i+b.size()-1<a1.size()&&j<b.size();j++){
	if (a1[i+j]!=b[j]){
	t=false;
	break;
	}
	}
	if (t){
	return i;
	}
	}
	return -1;
}
void cheak(int x,string a1,string b,string c){
	for (int i=0;i<b.size();i++){
	a1[x+i]=b[i];
	}
	if (a1==c){
	ans++;
	}
}
int main() {
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	cin >> n >> q;
	for (int i=1;i<=n;i++){
	cin >> a[i][1] >> a[i][2];
	}
	for (int i=1;i<=q;i++){
	cin >> t1 >> t2;
	ans=0;
	for (int j=1;j<=n;j++){
	if (find(t1,a[j][1])!=-1){
	cheak(find(t1,a[j][1]),t1,a[j][2],t2);
	}
	}
	cout << ans << endl;
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
