#include<bits/stdc++.h>
using namespace std;
int n,q;
vector<pair<string,string> > D[200005];
int pos;
map<pair<string,string>,int> mp;
int ans[200005];
int rnk(string A,string B){
   if(!mp[make_pair(A,B)])return mp[make_pair(A,B)]=++pos;
   return mp[make_pair(A,B)];
}
class Trie{
   public:
   int ch[5000005][26];
   vector<int> need[5000005];
   vector<pair<int,string> > Q[5000005];
   int rt[400005];
   int val[5000005];
   int tot;
   int insert(int id,string S){//
      if(!rt[id])rt[id]=++tot;
      int now=rt[id];
      // printf("now=%d %d %lu\n",now,rt[id],S.size());
      for(int i=0;i<S.size();i++){
         if(!ch[now][S[i]-'a']){
            ch[now][S[i]-'a']=++tot;
         }
         now=ch[now][S[i]-'a'];
      }
      // printf("now=%d %d %lu\n",now,rt[id],S.size());
      return now;
   }
   int query(int id,string S){
      int now=rt[id];
      for(int i=0;i<S.size();i++){
         if(!ch[now][S[i]-'a'])return now;
         now=ch[now][S[i]-'a'];
      }
      return now;
   }
   int getval(int id,string S){
      int now=rt[id];
      int sum=val[now];
      for(int i=0;i<S.size();i++){
         now=ch[now][S[i]-'a'];
         sum+=val[now];;
         // printf("now=%d sum=%d %c\n",now,sum,S[i]);
      }
      return sum;
   }
   void getans(int id,int now){
      for(int v:need[now]){
         // assert(v);
         // printf("Add v=%d\n",v);
         val[v]++;
      }
      for(auto v:Q[now]){
         ans[v.first]=getval(id+n,v.second);
         // if(v.first==173){
         //    printf("id=%d\n",id);
         //    cout<<v.second<<'\n';
         //    cerr<<ans[v.first]<<'\n';
         // }
      }
      for(int i=0;i<26;i++){
         if(ch[now][i])getans(id,ch[now][i]);
      }
      for(int v:need[now]){
         // printf("Del v=%d\n",v);
         val[v]--;
      }
   }
}P;
int main(){
   freopen("replace.in","r",stdin);
   freopen("replace.out","w",stdout);
   scanf("%d%d",&n,&q);
   // printf("n=%d\n",n);
   for(int i=1;i<=n;i++){//
   // printf("i=%d\n",i);
      string A,B;
      cin>>A>>B;
      // cout<<A<<' '<<B<<'\n';
      // continue;
      if(A==B){
         continue;
      }
      // if(A=="n"&&B=="j"){
      //    printf("i=%d\n",i);
      // }
      int L=0,R=A.size()-1;
      while(A[L]==B[L])L++;
      while(A[R]==B[R])R--;
      string tA="",tB="";
      for(int j=L;j<=R;j++){
         tA+=A[j],tB+=B[j];
      }
      string Sl="",Sr="";
      for(int j=L-1;j>=0;j--){
         Sl+=A[j];
      }
      for(int j=R+1;j<A.size();j++){
         Sr+=B[j];
      }
      // cout<<"START\n";
      // cout<<A<<' '<<B<<'\n';
      // cout<<tA<<' '<<tB<<'\n';
      // if(tA=="uyucqryhrjmrrcmfastozgdyvnnejyokornvimwzaijuqsienpfofktwhydvztgxpavjrp"){
      //    if(Sr=="av"){
      //       puts("???");
      //    }
      // }
      // cout<<Sl<<' '<<Sr<<'\n';
      int id=rnk(tA,tB);
      L=P.insert(id,Sl);
      R=P.insert(id+n,Sr);
      // printf("id=%d L=%d R=%d\n",id,L,R);
      // cout<<tA<<' '<<tB<<'\n';
      // if(tA[0]==tB[0])assert(0);
      // cout<<Sl<<' '<<Sr<<'\n';
      P.need[L].push_back(R);
      D[id].push_back(make_pair(Sl,Sr));
   }
   // return 0;
   for(int i=1;i<=q;i++){
      string A,B;
      cin>>A>>B;
      // if(i!=173)continue;
      // if(i!=27549)continue;
      // if(i+2!=q)continue;
      // cout<<A<<' '<<B<<'\n';
      // continue;
      int L=0,R=A.size()-1;
      while(A[L]==B[L])L++;
      while(A[R]==B[R])R--;
      string tA="",tB="";
      for(int j=L;j<=R;j++){
         tA+=A[j],tB+=B[j];
      }
      // cout<<tA<<' '<<tB<<'\n';
      if(!mp[make_pair(tA,tB)])continue;
      int id=rnk(tA,tB);
      string Sl="",Sr="";
      for(int j=L-1;j>=0;j--){
         Sl+=A[j];
      }
      for(int j=R+1;j<A.size();j++){
         Sr+=B[j];
      }
      // if(i==173){
      //    cout<<A<<' '<<B<<'\n';
      //    cout<<tA<<' '<<tB<<'\n';
      //    cout<<Sl<<' '<<Sr<<'\n';
      //    // printf("")
      // }
      // cout<<tA<<' '<<tB<<'\n';
      // cout<<Sl<<' '<<Sr<<'\n';
      L=P.query(id,Sl);
      P.Q[L].push_back(make_pair(i,Sr));
      // for(int j=0;j<D[id].size();j++){
      //    bool flg=false;
      //    for(int k=0;k<D[id][j].first.size();k++){
      //       if(k>=Sl.size()){
      //          flg=true;
      //          break;
      //       }
      //       if(D[id][j].first[k]!=Sl[k])flg=true;
      //    }
      //    for(int k=0;k<D[id][j].second.size();k++){
      //       if(k>=Sr.size()){
      //          flg=true;
      //          break;
      //       }
      //       if(D[id][j].second[k]!=Sr[k])flg=true;
      //    }
      //    if(!flg){
      //       cout<<D[id][j].first<<' '<<D[id][j].second<<'\n';
      //       ans[i]++;
      //    }
      // }
   }
   for(int i=1;i<=n;i++){
      // if(i!=101)continue;
      P.getans(i,P.rt[i]);
   }
   // printf("%d\n",ans[173]);
   // return 0;
   for(int i=1;i<=q;i++){
      printf("%d\n",ans[i]);
   }
   return 0;
}
/*
考虑一个替换字符串，将其实际操作的区间搞出来。

那么显然最后只有实际操作字符串相同的才有资格比。

然后把大家的实际操作字符串都删掉上 AC 自动机就行了。

字典树就行。

考虑搞完了之后怎么取交。

我能够求出一边在的情况，但是显然没办法全部标记。

考虑q比较小？

now=220 sum=4
now=221 sum=13
now=222 sum=15
now=223 sum=17
now=224 sum=21
now=225 sum=23
now=1448 sum=25
now=1449 sum=27
now=1450 sum=27
now=1451 sum=31
now=1452 sum=31
now=1453 sum=31
now=1454 sum=33
now=1455 sum=33
now=1456 sum=35
now=1457 sum=36
now=1458 sum=36
now=1459 sum=38
now=1460 sum=38
now=1461 sum=38
now=1462 sum=41
now=1463 sum=41
now=1464 sum=41
now=1465 sum=41
now=1466 sum=41
now=2633 sum=41
now=2634 sum=41
now=2635 sum=41
now=2636 sum=41
now=2637 sum=41
now=2638 sum=41
now=4253 sum=41
now=4254 sum=41
now=4255 sum=41
now=4256 sum=41
now=4257 sum=41
now=4258 sum=41
now=4259 sum=41
now=4260 sum=41
now=4261 sum=41
now=4262 sum=41
now=4263 sum=42
now=4264 sum=42
now=4265 sum=42
now=4266 sum=42
now=4267 sum=42
now=4268 sum=42
now=4269 sum=42
now=4462 sum=42
now=4463 sum=42
now=4464 sum=42
now=4465 sum=42


dbe av
d avyxvtdobnaagrqnaqmlo
dbege avyxvtdobnaagrqnaqmlorogknljpaacytjbblfjjx
dbegeajpgffrnjchgwxriyckjeokptbzakangmfeo avyxvtdobnaagrqn
Sl=dbegeajpgffrnjchgwxriyckjeokptbzakangmfeoubyrquypehwcsbppayghrnpsatsjna
Sr=avyxvtdobnaagrqnaqmlorogknljpaacytjbblfjjxzjyoslzkgs
*/
