#include<bits/stdc++.h>
#define let long long
#define rt return
using namespace std;
let t,n,
	cnt_a,cnt_b,cnt_c,
	f_a = 1,f_b = 1,f_c = 1,
	ans_a,ans_b,
	vis[100010];
struct node_id{
	let id,cnt;
}mp_a[100010],mp_b[100010],mp_c[100010];
struct node_sum{
	let idx,cnt;
};
struct node{
	let id,a,b,c;
}mp[100010];
bool cmp_a_b(node x,node y){
	if(x.a!=y.a)rt x.a<y.a;
	else {
		if(x.b!=y.b)rt x.b>y.b;
		rt x.c>y.c;
	}
}
bool cmp_b_b(node x,node y){
	if(x.b!=y.b)rt x.b<y.b;
	else {
		if(x.a!=y.a)rt x.a>y.a;
		rt x.c>y.c;
	}
}
bool cmp_c_b(node x,node y){
	if(x.c!=y.c)rt x.c<y.c;
	else {
		if(x.a!=y.a)rt x.a>y.a;
		rt x.b>y.b;
	}
}
bool cmp_a_a(node x,node y){
	if(x.a!=y.a)rt x.a>y.a;
	else {
		if(x.b!=y.b)rt x.b<y.b;
		rt x.c<y.c;
	}
}
bool cmp_b_a(node x,node y){
	if(x.b!=y.b)rt x.b>y.b;
	else {
		if(x.a!=y.a)rt x.a<y.a;
		rt x.c<y.c;
	}
}
bool cmp_c_a(node x,node y){
	if(x.c!=y.c)rt x.c>y.c;
	else {
		if(x.a!=y.a)rt x.a<y.a;
		rt x.b<y.b;
	}
}
bool cmp_s(node_sum x,node_sum y){
	rt x.cnt>y.cnt;
}
void solve(){
	cnt_a=cnt_b=cnt_c = 0;
	f_a = 1,f_b = 1,f_c = 1;
	ans_a = ans_b = 0;
	memset(vis,0,sizeof vis); 
	
	cin>>n;
	for(let i = 1;i<=n;i++)cin>>mp[i].a >>mp[i].b >>mp[i].c ;
	for(let i = 1;i<=n;i++)mp[i].id = i;
	//A:
	sort(mp+1,mp+n+1,cmp_a_a);
//	cout<<"A\n";
	for(let i = 1;i<=n;i++)mp_a[i].cnt = mp[i].a,mp_a[i].id = mp[i].id;//,cout<<mp_a[i].id<<" "<<mp_a[i].cnt<<"\n";
//	cout<<"B\n";
	sort(mp+1,mp+n+1,cmp_b_a);
	for(let i = 1;i<=n;i++)mp_b[i].cnt = mp[i].b,mp_b[i].id = mp[i].id;//,cout<<mp_b[i].id<<" "<<mp_b[i].cnt<<"\n";
//	cout<<"C\n";
	sort(mp+1,mp+n+1,cmp_c_a);
	for(let i = 1;i<=n;i++)mp_c[i].cnt = mp[i].c,mp_c[i].id = mp[i].id;//,cout<<mp_c[i].id<<" "<<mp_c[i].cnt<<"\n";
	
	let i = 1,j = 1,k = 1,idx = 1;;
	while(i<=n&&j<=n&&k<=n){
		
		node_sum s[10];
		s[1].cnt = mp_a[i].cnt,s[1].idx = 1;
		s[2].cnt = mp_b[j].cnt,s[2].idx = 2;
		s[3].cnt = mp_c[k].cnt,s[3].idx = 3;
		sort(s+1,s+4,cmp_s);
		for(let l = 1;l<=3;l++){
		//	cout<<s[l].idx<<"\n";
			if(s[l].idx == 1&&f_a){
				vis[mp_a[i].id] = 1;
				ans_a+=mp_a[i].cnt;
				i++;
				cnt_a++;
				break;
			}
			if(s[l].idx == 2&&f_b){
				vis[mp_b[j].id] = 1;
				ans_a+=mp_b[j].cnt;
				j++;
				cnt_b++;
				break;
			}
			if(s[l].idx == 3&&f_c){
				vis[mp_c[k].id] = 1;
				ans_a+=mp_c[k].cnt;
				k++;
				cnt_c++;
				break;
			}
		}
		while(vis[mp_a[i].id ]) i++;
		while(vis[mp_b[j].id ]) j++;
		while(vis[mp_c[k].id ]) k++;
		if(cnt_a>=n/2&&f_a) f_a = 0;
		if(cnt_b>=n/2&&f_b) f_b = 0;
		if(cnt_c>=n/2&&f_c) f_c = 0;
		//cout<<ans_a<<"  i:  "<<i<<"  j:  "<<j<<"  k:  "<<k<<"  idx  "<<idx<<"\n";
//		for(let i  =1;i<=n;i++)cout<<vis[i]<<" ";
//		cout<<"\n";
		idx++;
	}
	
	//B:
		
	cnt_a=cnt_b=cnt_c = 0;
	f_a = 1,f_b = 1,f_c = 1;
	memset(vis,0,sizeof vis); 
	
	sort(mp+1,mp+n+1,cmp_a_b);
//	cout<<"A\n";
	for(let i = 1;i<=n;i++)mp_a[i].cnt = mp[i].a,mp_a[i].id = mp[i].id;//,cout<<mp_a[i].id<<" "<<mp_a[i].cnt<<"\n";
//	cout<<"B\n";
	sort(mp+1,mp+n+1,cmp_b_b);
	for(let i = 1;i<=n;i++)mp_b[i].cnt = mp[i].b,mp_b[i].id = mp[i].id;//,cout<<mp_b[i].id<<" "<<mp_b[i].cnt<<"\n";
//	cout<<"C\n";
	sort(mp+1,mp+n+1,cmp_c_b);
	for(let i = 1;i<=n;i++)mp_c[i].cnt = mp[i].c,mp_c[i].id = mp[i].id;//,cout<<mp_c[i].id<<" "<<mp_c[i].cnt<<"\n";
	
	i = 1,j = 1,k = 1,idx = 1;;
	while(i<=n&&j<=n&&k<=n){
		
		node_sum s[10];
		s[1].cnt = mp_a[i].cnt,s[1].idx = 1;
		s[2].cnt = mp_b[j].cnt,s[2].idx = 2;
		s[3].cnt = mp_c[k].cnt,s[3].idx = 3;
		sort(s+1,s+4,cmp_s);
		for(let l = 1;l<=3;l++){
		//	cout<<s[l].idx<<"\n";
			if(s[l].idx == 1&&f_a){
				vis[mp_a[i].id] = 1;
				ans_b+=mp_a[i].cnt;
				i++;
				cnt_a++;
				break;
			}
			if(s[l].idx == 2&&f_b){
				vis[mp_b[j].id] = 1;
				ans_b+=mp_b[j].cnt;
				j++;
				cnt_b++;
				break;
			}
			if(s[l].idx == 3&&f_c){
				vis[mp_c[k].id] = 1;
				ans_b+=mp_c[k].cnt;
				k++;
				cnt_c++;
				break;
			}
		}
		while(vis[mp_a[i].id ]) i++;
		while(vis[mp_b[j].id ]) j++;
		while(vis[mp_c[k].id ]) k++;
		if(cnt_a>=n/2&&f_a) f_a = 0;
		if(cnt_b>=n/2&&f_b) f_b = 0;
		if(cnt_c>=n/2&&f_c) f_c = 0;
	//	cout<<ans_b<<"  i:  "<<i<<"  j:  "<<j<<"  k:  "<<k<<"  idx  "<<idx<<"\n";
	//	for(let i  =1;i<=n;i++)cout<<vis[i]<<" ";
	//	cout<<"\n";
		idx++;
	}
//	cout<<ans_a<<" ";
	cout<<max(ans_a,ans_b)<<"\n";
	
}
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>t;
	while(t--)solve();
	fclose(stdin);
	fclose(stdout);
	rt 0;
}
//		if(mp_a[i].cnt >=mp_b[j].cnt &&mp_a[i].cnt >=mp_c[k].cnt &&f_a){
//			vis[mp_a[i].id] = 1;
//			ans+=mp_a[i].cnt;
//			i++;
//			cnt_a++;
//	//		cout<<" id  "<<mp_a[i].id<<"\n";
//		
//		}else if(mp_b[j].cnt >=mp_a[i].cnt &&mp_b[j].cnt >=mp_c[k].cnt &&f_b){
//			vis[mp_b[j].id] = 1;
//			ans+=mp_b[j].cnt;
//			j++;
//			cnt_b++;
//	//		cout<<" id  "<<mp_b[j].id<<"\n";
//		}else if(mp_c[k].cnt >=mp_a[i].cnt &&mp_c[k].cnt >=mp_b[j].cnt &&f_c){
//			
//			vis[mp_c[k].id] = 1;
//			ans+=mp_c[k].cnt;
//			k++;
//			cnt_c++;
//	//		cout<<" id  "<<mp_c[k].id<<"\n";
//		}


