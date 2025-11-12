#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

ll t, n, a[4][100005];
ll s1, s2, s3, l1, l2, l3;
int j1[100005], j2[100005], j3[100005];
bool cmp1(int a1, int a2){
	return a[1][a1]-max(a[2][a1], a[3][a1])>a[1][a2]-max(a[2][a2], a[3][a2]);
}
bool cmp2(int a1, int a2){
	return a[2][a1]-max(a[1][a1], a[3][a1])>a[2][a2]-max(a[1][a2], a[3][a2]);
}
bool cmp3(int a1, int a2){
	return a[3][a1]-max(a[1][a1], a[2][a1])>a[3][a2]-max(a[1][a2], a[2][a2]);
}
bool c1(int a1, int a2){
	return abs(a[2][a1]-a[3][a1])>abs(a[2][a2]-a[3][a2]);
}
bool c2(int a1, int a2){
	return abs(a[1][a1]-a[3][a1])>abs(a[1][a2]-a[3][a2]);
}
bool c3(int a1, int a2){
	return abs(a[2][a1]-a[1][a1])>abs(a[2][a2]-a[1][a2]);
}
int main(){
	freopen("club.in", "r", stdin);
	freopen("club.out", "w", stdout);
	cin >> t;
	while(t--){
		cin >> n;
		l1=0; l2=0; l3=0; s1=0; s2=0; s3=0;
		memset(a, 0, sizeof(a));
		memset(j1, 0, sizeof(a));
		memset(j2, 0, sizeof(a));
		memset(j3, 0, sizeof(a));
		for(ll i=1; i<=n; i++){
			cin >> a[1][i] >> a[2][i] >> a[3][i];
			if(a[1][i]>=max(a[2][i], a[3][i])){
				l1++;
				j1[l1] = i;
				s1+=a[1][i];
			}
			else if(a[2][i]>=max(a[1][i], a[3][i])){
				l2++;
				j2[l2] = i;
				s2+=a[2][i];
			}
			else{
				l3++;
				j3[l3] = i;
				s3+=a[3][i];
			}
		}
		n/=2;
		if(l1>n){
			sort(j1+1, j1+l1+1, cmp1);
			for(int i=l1; i>n; i--, l1--){
				s1-=a[1][j1[i]];
				if(a[2][j1[i]]>a[3][j1[i]]){
					l2++;
					j2[l2]=j1[i];
					s2+=a[2][j1[i]];
				}
				else{
					l3++;
					j3[l3]=j1[i];
					s3+=a[3][j1[i]];
				}
			}
			if(l2>n){
				sort(j2+1, j2+l2+1, c1);
				for(int i=l2; i>n; i--){
					s2-=a[2][j2[i]];
					s3+=a[3][j2[i]];
					l2--;
					l3++;
				}
			}
			else{
				sort(j3+1, j3+l3+1, c1);
				for(int i=l3; i>n; i--){
					s3-=a[3][j3[i]];
					s2+=a[2][j3[i]];
					l3--;
					l2++;
				}
			}	
		}
		else if(l2>n){
			sort(j2+1, j2+l2+1, cmp2);
			for(int i=l2; i>n; i--, l2--){
				s2-=a[2][j2[i]];
				if(a[1][j2[i]]>a[3][j2[i]]){
					l1++;
					j1[l1]=j2[i];
					s1+=a[2][j2[i]];
				}
				else{
					l3++;
					j3[l3]=j2[i];
					s3+=a[3][j2[i]];
				}
			}
			if(l3>n){
				sort(j3+1, j3+l3+1, c2);
				for(int i=l3; i>n; i--){
					s3-=a[3][j3[i]];
					s1+=a[1][j3[i]];
					l3--;
					l1++;
				}
			}
			else{
				sort(j1+1, j1+l1+1, c2);
				for(int i=l1; i>n; i--){
					s1-=a[1][j1[i]];
					s3+=a[3][j1[i]];
					l1--;
					l3++;
				}
			}
		}
		else{
			sort(j3+1, j3+l3+1, cmp3);
			for(int i=l3; i>n; i--, l3--){
				s3-=a[3][j3[i]];
				if(a[1][j3[i]]>a[2][j3[i]]){
					l1++;
					j1[l1]=j3[i];
					s1+=a[2][j3[i]];
				}
				else{
					l2++;
					j2[l2]=j3[i];
					s2+=a[3][j3[i]];
				}
			}
			if(l2>n){
				sort(j2+1, j2+l2+1, c3);
				for(int i=l2; i>n; i--){
					s2-=a[2][j2[i]];
					s1+=a[1][j2[i]];
					l2--;
					l1++;
				}
			}
			else{
				sort(j1+1, j1+l1+1, c3);
				for(int i=l1; i>n; i--){
					s1-=a[1][j1[i]];
					s2+=a[2][j1[i]];
					l1--;
					l2++;
				}
			}
		}
		cout << s1+s2+s3 << '\n';
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
