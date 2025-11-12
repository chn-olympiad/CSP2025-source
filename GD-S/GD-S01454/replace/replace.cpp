#include<bits/stdc++.h>
using namespace std;
map<string ,string>q;
map<string , bool>q2;
string s1 , s2; 
int n , m;
string s4;
int ans;
int main(){
	freopen("replace.in" ,"r" , stdin);
	freopen("replace.out" , "w" , stdout); 
	cin >> n >> m;
	for(int i = 1 ;i <= n ;i++){
		cin >> s1 >> s2;
		q[s1] = s2;
		q2[s1] = 1;
	}
	while(m--){
		ans = 0;
		cin >> s1 >> s2;
		for(int i = 0 ;i <= n ;i++){	
			s4 = "";
			int p = 1;
			while(p <= i){
				s4 += s1[p];
				p++;
			}
			string s3 = "";
			int j = i + 1;
			while(j <= n){
			string s5 = s4;
				s3 += s1[j];
//				cout <<s3 << endl;
				if(q2[s3]){
					s5 += q[s3];
					for(int k = j + 1 ; j <= n ;j++){
						s5 += s1[k];
					}
					if(s5 == s2){
						ans++; 
					}										
				}
				j++;
			}
		}
		cout << ans << endl;		
	}
	return 0;
} 
