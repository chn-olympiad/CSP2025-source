#include<bits/stdc++.h>
using namespace std;
//priority_queue 背叛了我。 
//一道题都没写出来，尽管如此
//ccf long live
//ccf long live
//ccf long live
//ccf long live
//ccf long live
//ccf long live
//ccf long live
//ccf long live
//ccf long live
unsigned int n,ans;
struct person{
	int a[3],ch,cha[3];
}p[100005];
bool cmp(person x,person y){
	int xu[3],yu[3];
	sort(x.a,x.a+2);sort(y.a,y.a+2);
	xu[0]=x.a[0],xu[1]=x.a[1],xu[2]=x.a[2];
	yu[0]=y.a[0],yu[1]=y.a[1],yu[2]=y.a[2];
	if(xu[2]!=yu[2])return xu[2]<yu[2];
	else{
		if(xu[1]!=yu[1])return xu[1]>yu[1];
		else return xu[0]>yu[0];
	}
}
/*
bool operator<(person x,person y){
	if(x.ch==0){
		return max(x.cha[1],x.cha[2])>max(y.cha[1],y.cha[2]);
	}else if(x.ch==1){
		return max(x.cha[0],x.cha[2])>max(y.cha[0],y.cha[2]);
	}else if(x.ch==2){
		return max(x.cha[0],x.cha[1])>max(y.cha[0],y.cha[1]);
	}
	return false;
}
priority_queue<person> ca,cb,cc;*/
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	int t;
	cin>>t;
	while(t--){
		cin>>n;
		for(unsigned int i=1;i<=n;i++)cin>>p[i].a[0]>>p[i].a[1]>>p[i].a[2];
		sort(p+1,p+n+1,cmp);
		for(unsigned int i=1;i<=n/2;i++)ans+=p[i].a[0];
		/*for(unsigned int i=1;i<=n;i++){
			int xu[3];
			xu[0]=p[i].a[0],xu[1]=p[i].a[1],xu[2]=p[i].a[2];
			if(xu[0]>=xu[1]&&xu[0]>=xu[2]){
				if(ca.size()<n/2){
					person temp={{xu[0],xu[1],xu[2]},0,{0,xu[0]-xu[1],xu[0]-xu[2]}};
					ca.push(temp);
				}else{
					person temp=ca.top();
					if(max(temp.cha[1],temp.cha[2])<xu[0]){
						ca.pop();
						if(temp.cha[1]<temp.cha[2]){
							person tmp=temp;
							tmp.ch=1;
							tmp.cha[0]=tmp.a[1]-tmp.a[0];
							tmp.cha[1]=0;
							tmp.cha[2]=tmp.a[1]-tmp.a[2];
							cb.push(tmp);
						}
						else{
							person tmp=temp;
							tmp.ch=2;
							tmp.cha[0]=tmp.a[2]-tmp.a[0];
							tmp.cha[1]=tmp.a[2]-tmp.a[1];
							tmp.cha[2]=0;
							cc.push(tmp);
						}
						ca.push({{xu[0],xu[1],xu[2]},0,{0,xu[0]-xu[1],xu[0]-xu[2]}});
					}else{
						if(xu[1]>xu[2]){
							person tmp={xu[0],xu[1],xu[2],1,{xu[1]-xu[0],0,xu[1]-xu[2]}};
							cb.push(tmp);
						}
					}
				}
			}else if(xu[1]>=xu[0]&&xu[1]>=xu[2]){
				if(cb.size()<n/2){
					person temp={{xu[0],xu[1],xu[2]},1,{xu[1]-xu[0],0,xu[1]-xu[2]}};
					cb.push(temp);
				}else{
					person temp=cb.top();
					if(max(temp.cha[0],temp.cha[2])<xu[1]){
						cb.pop();
						if(temp.cha[0]<temp.cha[2]){
							person tmp=temp;
							tmp.ch=0;
							tmp.cha[0]=0;
							tmp.cha[1]=tmp.a[0]-tmp.a[1];
							tmp.cha[2]=tmp.a[0]-tmp.a[2];
							ca.push(tmp);
						}
						else{
							person tmp=temp;
							tmp.ch=2;
							tmp.cha[0]=tmp.a[2]-tmp.a[0];
							tmp.cha[1]=tmp.a[2]-tmp.a[1];
							tmp.cha[2]=0;
							cc.push(tmp);
						}
						cb.push({{xu[0],xu[1],xu[2]},1,{xu[1]-xu[0],0,xu[1]-xu[2]}});
					}
				}
			}else if(xu[2]>=xu[0]&&xu[2]>=xu[1]){
				if(cc.size()<n/2){
					person temp={{xu[0],xu[1],xu[2]},2,{xu[2]-xu[0],xu[2]-xu[1],0}};
					cc.push(temp);
				}else{
					person temp=cc.top();
					if(max(temp.cha[0],temp.cha[1])<xu[2]){
						cb.pop();
						if(temp.cha[0]<temp.cha[2]){
							person tmp=temp;
							tmp.ch=0;
							tmp.cha[0]=0;
							tmp.cha[1]=tmp.a[0]-tmp.a[1];
							tmp.cha[2]=tmp.a[0]-tmp.a[2];
							ca.push(tmp);
						}
						else{
							person tmp=temp;
							tmp.ch=1;
							tmp.cha[0]=tmp.a[1]-tmp.a[0];
							tmp.cha[1]=0;
							tmp.cha[2]=tmp.a[1]-tmp.a[2];
							cb.push(tmp);
						}
						cc.push({{xu[0],xu[1],xu[2]},2,{xu[2]-xu[0],xu[2]-xu[1],0}});
					}
				}
			}
		}
		int ans=0;
		while(!ca.empty()){
			ans+=ca.top().a[0];
			ca.pop();
		}
		while(!cb.empty()){
			ans+=cb.top().a[1];
			cb.pop();
		}
		while(!cc.empty()){
			ans+=cc.top().a[2];
			cc.pop();
		}*/
		cout<<ans<<endl;
	}
}
