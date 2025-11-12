#include<iostream>
#include<algorithm>
#include<vector>
#include<cstdio>

using namespace std;

struct V{
	long long l,r,x;
};
vector<V> p,q;
long long a[500005],s[500005],n,k,ans;
bool cmp(V c,V d){
	if(c.x==d.x){
		return c.l>d.l;		
	}else{
		return c.x<d.x;
	}

}

bool check(V c){
	if(q.empty()){
		return true;
	}else{
		for(V j:q){
			if(j.l==0){
				continue;
			}
			if((c.l<=j.r&&j.l<=c.l)||(c.r<=j.r&&j.l<=c.r)||(c.r>=j.r&&c.l<=j.l)){
				return false;
			}
		}
	}
	return true;
}


int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	
	cin>>n>>k;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	long long t=0,e=1;
	for(long long i=1;i<=n;i++){
		t=0;
		for(long long j=i;j<=n;j++){
			t^=a[j];
			if(t==k){
				p.resize(e);
				V temp;
				temp.l=i;
				temp.r=j;
				temp.x=j-i;
				p.push_back(temp);
				e++;
				break;
			}
		}
	}
	sort(p.begin(),p.end(),cmp);
	
	e=1;
	for(V i:p){
		//cout<<i.l<<' '<<i.r<<endl;
		if(i.l!=0&&check(i)){
			q.resize(e);
			ans++;
			q.push_back(i);
			e++;
		}

	}
	cout<<ans;

	
	return 0;
}
