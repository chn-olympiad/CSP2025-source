#include<bits/stdc++.h>
using namespace std;
typedef unsigned long long ull;
const ull B = 13131;
const int N=5000006;
ull Hashs1[N],Hashs2[N],P[N],Hasht1[N];
int n,q,l[N];
string s;
void init(){
	P[0]=1;
	for(int i=1;i<=5000000;i++){
		P[i] = P[i-1]*B;
	}
}
ull getHash(int l,int r){
	return Hasht1[r]-P[r-l+1]*Hasht1[l-1];
}
int main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	cin>>n>>q;
	init();
	for(int i=1;i<=n;i++) {
		string s1,s2;
		cin>>s1>>s2;
		int len = s1.length();
		s1 = ' '+s1; s2=' '+s2;
		ull H1=0,H2=0;
		for(int j=1;j<=len;j++){
			H1 = H1*B + s1[j];
			H2 = H2*B + s2[j];
		}
		Hashs1[i] = H1; Hashs2[i]=H2;
		l[i] = len;
//		cout<<H1<<" "<<H2<<endl;
	}
	string t1,t2;
	while(q--){
		cin>>t1>>t2;
		int ans = 0;
		if(t1.length() != t2.length()){
			printf("0\n");
			continue;
		}
		int len = t1.length();
		t1 = ' '+t1; t2=' '+t2;
		ull H2=0,H1=0;
		for(int i=1;i<=len;i++){
			Hasht1[i] = Hasht1[i-1]*B+t1[i];
//			cout<<Hasht1[i]<<endl;
			H2 = H2*B+t2[i];
		}
//		cout<<"de:"<<getHash(5,5)<<endl;
		H1 = Hasht1[len];
		for(int i=1;i<=n;i++){
			for(int L=1;L+l[i]-1<=len;L++){
				int R = L+l[i]-1;
//				cout<<i<<" "<<L<<" "<<R<<" "<<getHash(L,R)<<" "<<Hashs1[i]<<endl;
				if(getHash(L,R)==Hashs1[i]){
//					cout<<i<<" "<<L<<" "<<R<<endl;
					ull lHash = Hashs2[i]+P[R-L+1]*Hasht1[L-1];
//					cout<<lHash<<endl<<;
					if(H1 - Hasht1[R] + lHash == H2) ans++;	
				}
			}
		}
		printf("%d\n",ans);
	}
	return 0;
}
