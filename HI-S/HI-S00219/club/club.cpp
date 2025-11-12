#include<bits/stdc++.h>
using namespace std;

int t,n,m,tmp;

//multiset<int> n_equ_2_multiset;

vector<int> n_equ_2_vector;

struct member {
	int a,b,c;
} members[10010];

bool bc_zero_cmp(member x,member y) {
	return x.a>y.a ;
}

bool greater_to_smaller_cmp_for_int(int x,int y) {
	return x>y;
}

//bool h;
//bool flag;
//int q;

//bool n_equ_2_cmp(member x,member y) {
//
//}

int main() {
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>t;
	
	for(int k=t; k<=t; k++) {
		cin>>n;
		for(int i=1; i<=n; i++) {
			
			cin>>members[i].a>>members[i].b>>members[i].c;
			
			if(members[i].b+members[i].c==0) {
				tmp++;
			}
		}
		if(tmp==n) {

			sort(members+1,members+n+1,bc_zero_cmp);
			
			int ssum=0;
			
			for(int i=1; i<=n/2; i++) {
				ssum+=members[i].a;
			}
			cout<<ssum<<endl;

		} else if(n==2) {

//			int ssum=0;
//			int nmaxn1=-1;
//			int maxnpos1=-1;
//			int nmaxn2=-1;
//			int maxnpos2=-1;
//			if(members[1].a>members[1].b&&members[1].a>members[1].c){
//
//			}

			int ssum=0;

			n_equ_2_vector.push_back(members[1].a);
			n_equ_2_vector.push_back(members[1].b);
			n_equ_2_vector.push_back(members[1].c);

			sort(n_equ_2_vector.begin(),n_equ_2_vector.end(),greater_to_smaller_cmp_for_int);

			ssum+=n_equ_2_vector[0];

			if(ssum==members[1].a) {
				members[2].a=0;
			} else if( ssum==members[1].b) {
				members[2].b=0;
			} else if( ssum==members[1].c) {
				members[2].c=0;
			}

			n_equ_2_vector.clear();

			n_equ_2_vector.push_back(members[2].a);
			n_equ_2_vector.push_back(members[2].b);
			n_equ_2_vector.push_back(members[2].c);

			sort(n_equ_2_vector.begin(),n_equ_2_vector.end(),greater_to_smaller_cmp_for_int);

			ssum+=n_equ_2_vector[0];

//			n_equ_2_multiset.insert(members[1].a);
//			n_equ_2_multiset.insert(members[1].b);
//			n_equ_2_multiset.insert(members[1].c);
//
//			n_equ_2_multiset.insert(members[2].a);
//			n_equ_2_multiset.insert(members[2].b);
//			n_equ_2_multiset.insert(members[2].c);

			cout<<ssum<<endl;

		}
		
//		for(int i=1;i<=n;i++){
//			for(int j=1;j<=3;j++){
//				cout<<agree[j][i]<<" ";
//			}
//			cout<<endl;
//		}
//---------------------------------------
//		for(int i=1; i<=n; i++) {
//			cout<<members[i].a<<" "<<members[i].b<<" "<<members[i].c<<endl;
//		}


	}

//----------------------------------------------------------------------------------------------------------------------------------------

	fclose(stdin);
	fclose(stdout);

//-------

	return 0;
}


