#include<bits/stdc++.h>
using namespace std;
int n,q;
int l[3] [200010];
char s1[2500010],s2[2500010];
char t1[3010][2][200010];
int main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	cin >> n >> q;
	for (int i=0;i<n;i++){
		cin >> t1[i][0] >> t1[i][1];
		l[0][i]=strlen(s1);
		memcpy(s1,t1[i][0],l[0][i]);
		memcpy(s2,t1[i][1],l[0][i]);
		for (int j=0;j<l[0][i];j++){
			if (s1[j]=='b')
			l[1][i]=j;
			if (s2[j]=='b')
			l[2][i]=j;
		}
		l[2][i]-=l[1][i];
	}
	int ax,bx,cx;
	for (int i=0;i<q;i++){
		int ans=0;
		cin >> s1 >> s2;
		
		cx=strlen(s1);
		for (int j=0;j<cx;j++){
			if (s1[j]=='b')ax=j;
			if (s2[j]=='b')bx=j;
			if (s1[j]!='a' && s1[j]!='b') goto rey;
		}
		bx-=ax;
		for (int j=0;j<n;j++){
			if (l[1][j]<=ax && l[2][j]==bx && l[0][j]-l[1][j]<=cx-ax)
			ans++;
		}
		cout << ans << endl;
		rey:
			for (int j=0;j<q;j++){
				//for ()
			}
	}
	
}
