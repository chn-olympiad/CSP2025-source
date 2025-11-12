#include<cstdio>
#include<algorithm>

using namespace std;

int n,m,k;

struct node{
  int from;
  int to;
  int w;
};
node edge[2000001];
int s[10001];
long long answer=0;
int c[10001];
int arr[10001][11];
bool A=true;

int find(int rt){
  if(rt!=s[rt])s[rt]=find(s[rt]);
  return s[rt];
}

void merge(int x,int y){
  s[find(y)]=find(x);
}

bool cmp(node one,node two){
  return one.w<two.w;
}

long long func(){
  long long answer=0;
  for(int i=1;i<=n;i++){
    s[i]=i;
  }
  int cnt=0;
  sort(edge+1,edge+1+m,cmp);
  for(int i=1;i<=m;i++){
    if(find(edge[i].from)!=find(edge[i].to)){
      merge(edge[i].from,edge[i].to);
      cnt++;
      answer+=edge[i].w;
      if(cnt==n-1)break;
    }
  }
  return answer;
}

int main(){
  freopen("road.in","r",stdin);
  freopen("road.out","w",stdout);
  scanf("%d%d%d",&n,&m,&k);
  for(int i=1;i<=m;i++){
    scanf("%d%d%d",&edge[i].from,&edge[i].to,&edge[i].w);
  }
  for(int i=1;i<=k;i++){
    scanf("%d",&c[i]);
    if(c[i]!=0)A=false;
    for(int j=1;j<=n;j++){
      scanf("%d",&arr[j][i]);
    }
  }
  if(k==0){
    long long temp=func();
    printf("%lld\n",temp);
    return 0;
  }
  else if(A){


  }
  return 0;
}
