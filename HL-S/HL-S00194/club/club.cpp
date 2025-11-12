#include<bits/stdc++.h>
using namespace std;
struct node {
    int people,club,num;
};
bool cmp(node a,node b){
    return a.num>b.num;
}


void func( ){
	int ans=0;
    int a[4]={0};
    int n;cin>>n;
    bool person[n+1];
    for(int i=0;i<=n;i++) person[i]=0;
    int hlf=n/2;
    vector <node> doc;
    for(int i=1;i<=n;i++){
        int a,b,c;
        cin>>a>>b>>c;
        node d={i,1,a};
        doc.push_back(d);
        d={i,2,b};
        doc.push_back(d);
        d={i,3,c};
        doc.push_back(d);
    }
    sort(doc.begin(),doc.end(),cmp);
    for(node f:doc){
    	if(!person[f.people]&&a[f.club]<hlf){
    		ans+=f.num;
    		person[f.people]=1;
		}
	}
	cout<<ans;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    freopen("club.in","r",stdin);
    freopen("club.out","w",stdout);
    int n;
    cin>>n;
    for(int i=0;i<n;i++){
        func();cout<<"\n";
    }
    return 0;
}
