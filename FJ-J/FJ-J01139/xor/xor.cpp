#include<bits/stdc++.h>
using namespace std;
string s;
long long n,m,k,a[500001]={},alen,x,cnt,now,ctt,cntl;
struct node{
	long long l,r,len;
}qj[500001];
node lastt[500001];
bool cmp(node x,node y){
	if(x.len==y.len){
		return x.l<y.l;
	}
	return x.len<y.len;
}
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	scanf("%lld%lld",&n,&k);
	for(int i=1;i<=n;i++){
		scanf("%lld",&x);
	//	if(x!=0){
			a[++alen]=x;
	//	}
	}
	for(int i=1;i<=alen;i++){
		now=a[i];
	//	cout<<now<<" ";
		if(now==k){
				qj[++ctt]={i,i,1};continue;//cout<<endl;
		}
		for(int j=i+1;j<=alen;j++){
			now^=a[j];
	//		cout<<now<<" ";
			if(now==k){
				qj[++ctt]={i,j,j-i+1};break;//cout<<endl;
			}
			if(j==alen){
		//		cout<<"noooooooo!"<<endl;
			}
		}
	}
	sort(qj+1,qj+1+ctt,cmp);
	for(int i=1;i<=ctt;i++){
	//	cout<<qj[i].l<<' '<<qj[i].r<<' '<<cntl<<" "<<qj[i].len<<endl;
		int ctbl[500001]={},ct=0,ct2=0;
		for(int jjk=1;jjk<=cntl;jjk++){
			node j=lastt[jjk];
			if(j.len==0){
				continue;
			}
			if((j.l<=qj[i].r&&j.r>=qj[i].l)||(qj[i].r>=j.l&&qj[i].l<=j.r)){
				//cout<<1; 
				ct+=j.len;
				ct2++;
				ctbl[ct2]=jjk;
				break;
			}
		}
		if(ct>=qj[i].len||ct==0){
			for(int s=1;s<=ct2;s++){
				lastt[ctbl[s]]={-1,-1,0};
				cnt--;
			}
			cnt++;
			lastt[++cntl]={qj[i].l,qj[i].r,qj[i].len};
		}
	}
	printf("%lld",cnt);
	return 0;
}
