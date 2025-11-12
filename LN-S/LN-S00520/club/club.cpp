#include<bits/stdc++.h>
using namespace std;
const int N = 1e5+10;
struct man{
	int a;
	int b;
	int c;
} F[N],A[N],B[N],C[N];
long long zhia,zhib,zhic;
bool zhaoa(man e,man d){
	return min((e.a-e.b),(e.a-e.c))>min((d.a-d.b),(d.a-d.c));
}
bool zhaob(man e,man d){
	return min((e.b-e.a),(e.b-e.c))>min((d.b-d.a),(d.b-d.c));
}
bool zhaoc(man e,man d){
	return min((e.c-e.b),(e.c-e.a))>min((d.c-d.b),(d.c-d.a));
}
long long aaa,bbb,ccc;
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	int T ;
	cin>>T;
	while(T--){
		zhia=0,zhib=0,zhic=0;
		aaa=0,bbb=0,ccc=0;
		memset(F,0,sizeof F);
		memset(A,0,sizeof A);
		memset(B,0,sizeof B);
		memset(C,0,sizeof C);
		int n;
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>F[i].a>>F[i].b>>F[i].c;
		if(F[i].a>F[i].b&&F[i].a>F[i].c){
			 A[zhia]=F[i];
			 zhia++;
		 }
		else if(F[i].b>F[i].c&&F[i].b>F[i].a){
			 B[zhib]=F[i];
			 zhib++;
		 }
		else if(F[i].c>=F[i].b&&F[i].c>=F[i].a){
			 C[zhic]=F[i];
			 zhic++;
		 }
	}
    sort(B,B+zhib,zhaob);
    sort(A,A+zhia,zhaoa);
    sort(C,C+zhic,zhaoc);
    if(zhia>(n/2)){
		while(zhia>(n/2)){
			if((A[zhia-1].a-A[zhia-1].b)>(A[zhia-1].a-A[zhia].c)){
				C[zhic]=A[zhia-1];
				zhic++;
				zhia--;
			}
			else{
				B[zhib]=A[zhia-1];
				zhib++;
				zhia--;
			}	
		}
	}
	if(zhib>(n/2)){
		while(zhib>(n/2)){
			if((B[zhib-1].b-B[zhib-1].a)>(B[zhib-1].b-B[zhib].c)){
				C[zhic]=B[zhib-1];
				zhic++;
				zhib--;
			}
			else{
				A[zhia]=B[zhib-1];
				zhia++;
				zhib--;
			}	
		}
	}
	if(zhic>(n/2)){
		while(zhic>(n/2)){
			if((C[zhic-1].c-C[zhic-1].b)>(C[zhic-1].c-C[zhic-1].a)){
				A[zhia]=C[zhic-1];
				zhia++;
				zhic--;
			}
			else{
				B[zhib]=C[zhic-1];
				zhib++;
				zhic--;
			}	
		}
	}
	for(int i=0;i<zhia;i++){
		 aaa+=A[i].a;
	 }
	for(int i=0;i<zhib;i++) bbb+=B[i].b;
	for(int i=0;i<zhic;i++) ccc+=C[i].c;
	cout<<aaa+bbb+ccc<<endl;
}
return 0;
}
