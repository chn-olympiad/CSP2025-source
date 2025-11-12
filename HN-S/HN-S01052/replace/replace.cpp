#include<bits/stdc++.h>
#include<cstdio>
using namespace std;
const int N=2e5+10;
char sp[N], sp_[N];
int main(){
	freopen("replace.in", "r", stdin);
	freopen("replace.out", "w", stdout);
	//
	int n, q;
	scanf("%d%d", &n, &q);
	string s1, s2;
	int cnt=0;
	for(int i=0; i<n; i++){
		cin>>s1>>s2;
		for(int j=0; j<s1.size(); j++){
			if(s1[j]!=s2[j]){
				sp[cnt]=(char)s1[j];
				sp_[cnt]=(char)s2[j];
			}
			sp[cnt]='A';
			sp_[cnt]='A';
			cnt++;
		}
	}
	for(int k=0; k<q; k++){
		cin>>s1>>s2;
		if(s1.size()!=s2.size()){
			printf("0\n");
		}
		else{
			int sum=0;
			char y[N], y_[N];
			int cnt1=0;
			for(int i=0; i<s1.size()-1; i++){
				if(s1[i]!=s2[i]){
					y[cnt1]=s1[i];
					y_[cnt1]=s2[i];
					cnt1++;
				}
			}
			bool flag=true;
			int cont=0;
			for(int i=0; i<cnt; i++){
				if((cont==cnt1 && sp[i]!='A') || (cont!=cnt1 && sp[i]=='A')){
					cont=0;
				}
				if(sp[i]=='A' && flag){
					sum++;
				}
				else{
					if(y[cont]!=sp[i] || y_[cont]!=sp_[i]) flag=false;
					cont++;
				}
			}
			printf("%d\n", sum);
		}
	}
	//
	fclose(stdin);
	fclose(stdout);
	return 0;
}

