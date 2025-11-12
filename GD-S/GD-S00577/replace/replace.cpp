#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	string s1[200005],s2[200005],t1,t2;
	int n,q,m = 0;
	cin >> n >> q;
	for( int i = 0;i < n;i++ ){
		cin >> s1[i] >> s2[i];
		m++; 
	}
	while( q-- ){
		int ans = 0;
		string y1,y2;
		cin >> t1 >> t2;
		int l = t1.length();
		int p1 = 0,p2 = l - 1;
		while( 1 ){
			y1 = '\0',y2  = '\0';
			for( int i = p1;p1 <= p2;i++ ){
				y1 += t1[i] + y1;
				y2 += t2[i] + y2;
			}
			for( int i = 0;i < m;i++ ){
				if( y1 == s1[i] && y2 == s2[i] ){
					ans++;
					break; 
				}
			}
			if( t1[p2] == t2[p2] ){
				p2--;
			}
			else if( t1[p1] == t2[p1] ){
				p1++;
				p2 = l - 1;
			}
			else{
				break;
			}
		}
		cout << ans << '\n';
	}
	return 0;
}
