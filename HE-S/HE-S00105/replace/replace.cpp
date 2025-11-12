#include <bits/stdc++.h>
using namespace std;

int n,que,ans;
string s[200010][3],s1,s2,s3;
int a[200010][5];
int main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	cin >> n >> que;
	for(int i = 1;i<=n;i++){
		cin >> s[i][1] >> s[i][2];
	}
//	bool ffff = 0;
//	for(int i = 1;i<n;i++){
//		int s1sumb = 0,s2sumb = 0;
//		for(int j = 0;j<s[i][1].size();j++){
//			if(s[i][1][j] =='b'){
//				s1sumb++;
//			}
//			if((s[i][1][j] !='a' and s[i][1][j] !='b') or s1sumb >= 2){
//				ffff = 1;
//				break;
//			}
//			if(s[i][2][j] =='b'){
//				s2sumb++;
//			}
//			if((s[i][2][j] !='a' and s[i][2][j] !='b') or s2sumb >= 2){
//				ffff = 1;
//				break;
//			}
//		}
//		if(ffff == 1){
//			break;
//		}
//		int www = 0;
//		while(s[i][1][www] == 'a'){
//			a[i][1] ++;
//			www++;
//		}
//		a[i][2] = s[i][1].size() - a[i][1] - 1;
//		www = 0;
//		while(s[i][2][www] == 'a'){
//			a[i][3] ++;
//			www++;
//		}
//		a[i][4] = s[i][2].size() - a[i][3] - 1;
//	}
	for(int i = 1;i<=que;i++){
		ans = 0;
		cin >> s1 >> s2;
//		if(ffff == 0){
//			int s1sumb = 0,s2sumb = 0;
//			for(int j = 0;j<s1.size();j++){
//				if(s1[j] =='b'){
//					s1sumb++;
//				}
//				if((s1[j] !='a' and s1[j] !='b') or s1sumb >= 2){
//					ffff = 1;
//					break;
//				}
//				if(s2[j] =='b'){
//					s2sumb++;
//				}
//				if((s2[j] !='a' and s2[j] !='b') or s2sumb >= 2){
//					ffff = 1;
//					break;
//				}
//			}
//			if(ffff == 1){
//				break;
//			}
//		}
//		if(ffff == 0){
//			
//				int s1a1 = 0;
//				int www = 0;
//				while(s1[www] == 'a'){
//					s1a1 ++;
//					www++;
//				}
//				int s1a2 = s1.size() - s1a1 - 1;
//				int s2a1 = 0;
//				www = 0;
//				while(s2[www] == 'a'){
//					s2a1 ++;
//					www++;
//				}
//				int s2a2 = s2.size() - s2a1 - 1;
//				for(int ee = 1;ee<=que;ee++){
//					if(s1a1 >= a[ee][1] and s1a2 >= a[ee][2] and s2a1 >= a[ee][3] and s2a2 >= a[ee][4]){
//						ans++;
//					}
//				}
//				cout << ans << endl;
//				continue;
//			
//			
//		}
		//shibaidetepan
		s3 = s1;
		for(int j = 1;j<=n;j++){ 
			for(int q = 0;q<s1.size();q++){
				bool flag = 0;
				for(int w = 0;w<s[j][1].size();w++){
					if(s1[q+w] == s[j][1][w]){
						s3[q+w] = s[j][2][w];
					}else{
						flag = 1;
						s3 = s1;
						break;
					}
				}
				if(flag == 0){
					if(s3 == s2){
						ans++;				
					}
					s3 = s1;
				}
			}
		}
		cout << ans<<'\n';
	}
	
	
	
	return 0;
}
