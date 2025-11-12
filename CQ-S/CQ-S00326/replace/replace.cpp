#include<cstdio>
#include<cstring>
#include<iostream>
#include<algorithm>
#include<cmath>
using namespace std;
typedef long long int L;
L n,m,t,cnt,l1,l2,pi[2505],tmp1,tmp2,id,fr,bk;
string s1[1505],s2[1505],s3[1505],s4[1505],tmp3;
bool t1,t2;
int main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	cin >> n >> m;
	t1 = true;
	t2 = true;
	l1 = 0LL;
	l2 = 0LL;
	for(L i = 1LL;i <= n;i++){
		cin >> s1[i] >> s2[i];
		l1 += s1[i].length(),l1 += s2[i].length();
		if(t2){
			cnt = 0LL;
			for(L j = s1[i].length() - 1LL;j >= 0LL;j--){
				if(s1[i][j] == 'b'){cnt++;}
				else if(s1[i][j] != 'a'){t2 = false;break;}
			}
			if(cnt != 1LL){t2 = false;}
		}
		if(t2){
			cnt = 0LL;
			for(L j = s2[i].length() - 1LL;j >= 0LL;j--){
				if(s2[i][j] == 'b'){cnt++;}
				else if(s2[i][j] != 'a'){t2 = false;break;}
			}
			if(cnt != 1LL){t2 = false;}
		}
	}
	for(L i = 1LL;i <= m;i++){
		cin >> s3[i] >> s4[i];
		l2 += s3[i].length(),l2 += s4[i].length();
		if(t2){
			cnt = 0LL;
			for(L j = s3[i].length() - 1LL;j >= 0LL;j--){
				if(s3[i][j] == 'b'){cnt++;}
				else if(s3[i][j] != 'a'){t2 = false;break;}
			}
			if(cnt != 1LL){t2 = false;}
		}
		if(t2){
			cnt = 0LL;
			for(L j = s4[i].length() - 1LL;j >= 0LL;j--){
				if(s4[i][j] == 'b'){cnt++;}
				else if(s4[i][j] != 'a'){t2 = false;break;}
			}
			if(cnt != 1LL){t2 = false;}
		}
	}
	t1 = (l1 <= 2000LL && l2 <= 2000LL && n <= 1000LL && m <= 1000LL);
//	if(t1){
/*
		for(L i = 1LL;i <= m;i++){
			for(L j = 1LL;j <= n;j++){
				tmp1 = s1[i].length(),tmp2 = s3[i].length();
				pi[0] = 0LL;
				for(L ij = 1LL,ji;ij < tmp2;ij++){
					ji = pi[ij - 1LL];
					while(ji >= 0LL && s1[ji] != s3[ij]){ji = pi[ji - 1LL];}
					if(s1[ji] == s3[ij]){ji++;}
					pi[ij] = ji;
				}
				if(pi[ij] == tmp1 - 1LL){}else{;}
			}
		}*/
//		for(L i = 1LL;i <= m;i++){printf("0\n");}
//	}
//	else 
	if(t2){
		for(L i = 1LL,ans = 0LL;i <= m;i++){
			for(L j = 1LL;j <= n;j++){
				for(L ij = 0LL;s1[j][ij];ij++){
					if(s1[j][ij] == 'b'){
						id = j;
						fr = id;
						bk = s1[j].length() - id - 1LL;
						break;
					}
				}
				for(L ij = 0LL;s3[i][ij];ij++){
					if(s3[j][ij] == 'b'){
						if(ij + 1LL >= fr && ij + bk <= s3[i].length()){
							tmp3 = "";
							for(L ji = 0LL;ji + fr < ij;ji++){tmp3 += s3[i][ji];}
							for(L ji = 0LL;s1[j][ji];ji++){tmp3 += s1[j][ji];}
							for(L ji = ij + bk;s3[i][ji];ji++){tmp3 += s3[i][ji];}
							ans += (tmp3 == s4[i]);
						}
						break;
					}
				}
			}
			printf("%lld",ans);
			putchar('\n');
			ans = 0LL;
		}
	}
	else{
		for(L i = 1LL;i <= m;i++){printf("0\n");}
	}
	return 0;
}
