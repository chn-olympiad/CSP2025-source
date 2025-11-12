#include <bits/stdc++.h>
using namespace std;
string s[200005][3], t[200005][3];
int n, q, d[200005], ans;
struct node{
	int l, r;
}k[200005][2];
/*void zhao(int b){
	int j=0, len=s[i][b].size();
	int l=0, r=len-1;
    while (s[i][b][j]=='a' && j<l){
        k[i][b-1].l++;
		j++;
	}
	j++;
	while (s[i][b][j]=='a' && j<l){
		k[i][b-1].r++;
		j++;
	}
	return;
}*/
int main(){
    freopen("replace.in", "r", stdin);
    freopen("replace.out", "w", stdout);
    cin >> n >> q;
    for (int i=1; i<=n; i++){
        cin >> s[i][1] >> s[i][2];
        d[i]=s[i][1].size();
    }
    for (int i=1; i<=q; i++){
		ans=0;
		cin >> t[i][1] >> t[i][2];
		int l=t[i][1].size();
		for (int k=1; k<=n; k++){
			string x="", xx="";
		    string z, zz, y, yy;
		    for (int j=0; j<l && d[k]+j<=l; j++){
				z="",zz="";
				y=yy="";
				for (int a=j; a<j+d[k]; a++){
					y=y+t[i][1][a], yy=yy+t[i][2][a];
				}
				if (y==s[k][1] && yy==s[k][2]){
			        for (int a=j+d[k]; a<l; a++){
					    z=z+t[i][1][a], zz=zz+t[i][2][a];
				    }
				    string s1=x+s[k][1]+z;
				    string s2=xx+s[k][1]+zz;
				    //cout << x << ' ' << z << '\n';
				    //cout << xx << ' ' << zz << '\n';
				    if (s1==s2){
					    ans++;
				    }
				}
				x=x+t[i][1][j], xx=xx+t[i][2][j];
			}
		}
		printf("%d\n", ans);
	}
    return 0;
}
/*
3 4
a b
b c
c d
aa bb
aa b
a c
b a
*/
