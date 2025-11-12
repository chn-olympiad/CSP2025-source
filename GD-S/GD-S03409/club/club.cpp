#include<bits/stdc++.h>
using namespace std;
struct node{
	int a=0,id=0;
};
bool cmp1(node a,node b){
	return a.a>b.a;
}

int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	int t;
	cin>>t;
	while(t--){
		long long ans=0;
		int n,p=0,q=0,k=0,pp=0,qq=0,kk=0;
		cin>>n;
		vector<vector<int>>v;
		vector<node>a,b,c;
		int x=0,y=0,z=0;
		for(int i=0;i<n;i++){
			vector<int> vc;
			for(int j=0;j<3;j++){
				int x=0;
				cin>>x;
				vc.push_back(x);
			}
			node x;
			x.a=vc[0];
			x.id=i;
			a.push_back(x);
			x.a=vc[1];
			b.push_back(x);
			x.a=vc[2];
			c.push_back(x);
			v.push_back(vc);
		}
		sort(a.begin(),a.end(),cmp1);
		sort(b.begin(),b.end(),cmp1);
		sort(c.begin(),c.end(),cmp1);
//		for(int i=0;i<n;i++){
//			int maxn=max(v[i][0],max(v[i][1],v[i][2]));
//			if(maxn==v[i][0]){
//				if()
//			}
//		}
		for(int i=0;i<n;i++){
			//cout<<a[p].a<<' '<<b[q].a<<' '<<c[k].a<<' '<<(b[q].a>=a[p].a||p>=n/2)<<' '<<(b[q].a>=c[k].a)<<' '<<q<<endl;
			if((a[p].a>=b[q].a||q-qq>=n/2)&&(a[p].a>=c[k].a||k-kk>=n/2)&&p-pp<n/2){
			//cout<<"a:"<<a[p].id<<endl;
				ans+=a[p].a;
				v[a[p].id][0]=-1;
				v[a[p].id][1]=-1;
				v[a[p].id][2]=-1;
				p++;
			}
			else if((b[q].a>=a[p].a||p-pp>=n/2)&&(b[q].a>=c[k].a||k-kk>=n/2)&&q-qq<n/2){
			//	cout<<"b:"<<b[q].id<<endl;
				ans+=b[q].a;
				v[b[q].id][0]=-1;
				v[b[q].id][1]=-1;
				v[b[q].id][2]=-1;
				q++;
			}
			else if((c[k].a>=b[q].a||q-qq>=n/2)&&(c[k].a>=a[p].a||p-pp>=n/2)&&k-kk<n/2){
				//cout<<"c:"<<c[k].id<<endl;
				ans+=c[k].a;
				v[c[k].id][0]=-1;
				v[c[k].id][1]=-1;
				v[c[k].id][2]=-1;
				k++;
			}
			while(v[a[p].id][0]==-1&&p-pp<n/2&&p<n){
				p++;
				pp++;
			}
			while(v[b[q].id][1]==-1&&q-qq<n/2&&q<n){
				q++;
				qq++;
			}
			while(v[c[k].id][2]==-1&&k-kk<n/2&&k<n){
				k++;
				kk++;
			}
		}
		cout<<ans<<endl;
	}
	return 0;
} 
/*
3
  4
  4 2 1
  3 2 4
  5 3 4
  3 5 1
  4
  0 1 0
  0  1 0
  0 2 0
  0 2 0
  2
  10 9 8
  4 0 0
  */
