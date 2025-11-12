# include <bits/stdc++.h>
using namespace std;
int n,q,tot=0;
string s1[1005],s2[1005],t1,t2;
int s[200005],t[200005],l1[200005],l2[200005];
int main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	scanf("%d%d",&n,&q);
	for(int i = 1;i<=n;i++){
		cin>>s1[i]>>s2[i];
	}
	int num1,num2;
	for(int i = 1;i<=q;i++){
		cin>>t1>>t2;
		num1 = -1;num2 = 0;
		for(int j = 0;j<t1.length();j++){
			if (num1==-1&t1[j]!=t2[j]){
				num1 = j; num2 = j;
			}
			else if (t1[j]!=t2[j]) num2 = j;
		}
		tot = 0;
		for(int j = 1;j<=n;j++){
			if (s1[j].length()<num2-num1+1) continue;
			int l = num2-s1[j].length()+1,r = num2;
			while(r<t1.length()){
				int kp=0;
				for(int x = l;x<=r;x++){
					if (t1[x]!=s1[j][x-l]) {
						kp=1;
						break;
					}
				}
				for(int x = l;x<=r;x++){
					if (t2[x]!=s2[j][x-l]) {
						kp=1;
						break;
					}
				}
				if (kp==0) tot++;
				r++; l++;
			}
		}
		cout<<tot<<endl;
	}
	return 0;
}


