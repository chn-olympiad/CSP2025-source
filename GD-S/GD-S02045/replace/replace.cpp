#include <bits/stdc++.h>
using namespace std;
int n,q,cs1,cs2,z,num;
string x1[200005],x2[200005],y1,y2,s1,s2,f1,f2,d1,d2;
int main() {
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	scanf("%d%d",&n,&q);
	for(int i=1; i<=n; i++) {
		cin>>x1[i]>>x2[i];
	}
	for(int m=1; m<=q; m++) {
		cin>>y1>>y2;
		for(int i=1; i<=n; i++) {
			d1=y1;
			d2=y2;
			s1=x1[i];
			s2=x2[i];
			cs1=s1.size()-1;
			cs2=s2.size()-1;
			for(int j=0; j<y1.size()-cs1; j++) {
				f1=f2="";
				for(int o=j; o<=j+cs1; o++) {
					f1=f1+y1[o];
					f2=f2+y2[o];
				}
//			f1=y1.substr(j,j+cs1);
//			f2=y2.substr(j,j+cs1);
//			cout<<"j~j+sc1="<<j<<"~"<<j+cs1<<endl;
//			cout<<"f1="<<f1<<" f2="<<f2<<" s1="<<s1<<" s2="<<s2<<endl;
				if(f1==s1 && f2==s2) {
					z=0;
					for(int o=j; o<=j+cs1; o++) {
						y1[o]=s2[z++];
					}
				}
//			cout<<"y1="<<y1<<" y2="<<y2<<endl<<endl;
				if(y1==y2) {
					num++;
				}
				y1=d1;
				y2=d2;
			}
		}
		printf("%d\n",num);
		num=0;
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
