#include<bits/stdc++.h>
using namespace std;
const int N = 1e6 + 10;	
int a[N],b[N];
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	string st,s;
	cin >> st;
	int k = st.length();
	int maxx,minn;
	
	for(int i = 0;i < k;i ++){
		s[i] = st[i] - '0';
		//if(s[i] == 5)cout << st[i];
		
		if(s[i] == 1 || s[i] == 2 || s[i] == 3 || s[i] == 4 || s[i] == 5 || s[i] == 6 || s[i] == 7 || s[i] == 8 || s[i] == 9 || s[i] == 0){
			//cout << (int)s[i] << "\n";
			a[i] = (int)s[i];
			cout << a[i];
//		    maxx = max(a[i],maxx);
//		    b[i] = maxx;
		    
		}
			
	}
	return 0;
} 