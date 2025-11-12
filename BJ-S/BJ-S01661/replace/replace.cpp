#include<bits/stdc++.h>
using namespace std;
struct node{
    int a, b, c;
}d[100010];
int cmp(node x, node y){

    return max(max(x.a,x.b),x.c) > max(max(y.a,y.b),y.c);
}
int main(){
    freopen("club.in", "r", stdin);
    freopen("club.out", "w", stdout);
    int t;
    cin >> t;
    while(t--){
        int n;
        cin >> n;
        for(int i = 1; i <= n; i++){
            cin >> d[i].a >> d[i].b >> d[i].c;
        }
        sort(d+1,d+1+n,cmp);
        int x = 0;
        int y = 0;
        int z = 0;
        int xv = 0;
        int yv = 0;
        int zv = 0;
        priority_queue<int> ab;
        priority_queue<int> bc;
        priority_queue<int> ac;
        priority_queue<int> abc;
        for(int i = 1; i <= n; i++){
            if(d[i].a>d[i].b && d[i].a > d[i].c && d[i].b!=d[i].c){
                if(x+1>n/2){
                    if(d[i].b > d[i].c){
                        if(y+1 > n/2){
                            zv+=d[i].c;
                            z++;
                        }else{
                            yv+=d[i].b;
                            y++;
                        }
                    }else{
                        if(z+1>n/2){
                            yv+=d[i].b;
                            y++;
                        }else
                        {
                            zv+=d[i].c;
                            z++;

                        }
                    }
                }else
                {
                    x+=1;
                    xv+=d[i].a;

                }

            }
            else if(d[i].b>d[i].a && d[i].b > d[i].c && d[i].a!=d[i].c){
                if(y+1>n/2){
                    if(d[i].a > d[i].c){
                        if(x+1 > n/2){
                            zv+=d[i].c;
                            z++;
                        }else{
                            xv+=d[i].a;
                            x++;
                        }
                    }else{
                        if(z+1>n/2){
                            xv+=d[i].a;
                            x++;
                        }else{
                            zv+=d[i].c;
                            z++;
                        }
                    }
                }else{
                    y+=1;
                    yv+=d[i].b;
                }

            }
            else if(d[i].c>d[i].a && d[i].c > d[i].b && d[i].a!=d[i].b){
                if(y+1>n/2){
                    if(d[i].b > d[i].a){
                        if(x+1 > n/2){
                            xv+=d[i].a;
                            x++;
                        }else{
                            yv+=d[i].b;
                            y++;
                        }
                    }else{
                        if(z+1>n/2){
                            yv+=d[i].b;
                            y++;
                        }else{
                            xv+=d[i].a;
                            x++;
                        }
                    }
                }else{
                    z+=1;
                    zv+=d[i].c;
                }

            }else if(d[i].a == d[i].b && d[i].a == d[i].c){
                abc.push(d[i].a);
            }else if(d[i].a == d[i].b)
            {
                if(z+1<= n/2&&d[i].c > d[i].b){
                    zv+=d[i].c;
                    z++;
                }else ab.push(d[i].b);
            }else if(d[i].b == d[i].c){
                if(x+1<= n/2&&d[i].a > d[i].b){
                    xv+=d[i].a;
                    x++;
                }else bc.push(d[i].b);

            }else
            {
                if(y+1<= n/2&&d[i].b > d[i].c){
                    yv+=d[i].b;
                    y++;
                }else ac.push(d[i].a);

            }

        }
        for(int i = 1; i <= min(n/2-x, int(abc.size()+ab.size()+ac.size())); i++){
            if(abc.size() && abc.top() > ab.top() && abc.top() > ac.top()){
                xv += abc.top();
                abc.pop();
            }else if(ab.size() && ab.top() > abc.top() && ac.top() < ab.top() ){
                xv += ab.top();
                ab.pop();
            }else if(ac.size()&&ac.top() > abc.top() && ac.top() > ab.top()){
                xv += ac.top();
                ac.pop();
            }else{
                if(bc.size())
                {
                    xv += bc.top();
                    bc.pop();
                }else if(ab.size()){
                    xv += ab.top();
                    ab.pop();
                }else{
                    xv += abc.top();
                    abc.pop();
                }
            }
        }
        for(int i = 1; i <= min(n/2-y, int(abc.size()+ab.size()+bc.size())); i++){
            if(abc.size()&&abc.top() > ab.top() && abc.top() > bc.top()){
                yv += abc.top();
                abc.pop();
            }else if(ab.size() && ab.top() > abc.top() && bc.top() < ab.top() ){
                yv += ab.top();
                ab.pop();
            }else if(bc.size() && bc.top() > abc.top() && bc.top() > ab.top()){
                yv += bc.top();
                bc.pop();
            }else{
                if(bc.size())
                {
                    yv += bc.top();
                    bc.pop();
                }else if(ab.size()){
                    yv += ab.top();
                    ab.pop();
                }else{
                    yv += abc.top();
                    abc.pop();
                }


            }

        }
        for(int i = 1; i <= min(n/2-z, int(abc.size()+bc.size()+ac.size())); i++){
            if(abc.size()&&abc.top() > bc.top() && abc.top() > ac.top()){
                zv += abc.top();
                abc.pop();
            }else if(bc.size()&&bc.top() > abc.top() && ac.top() < bc.top() ){
                zv += bc.top();
                bc.pop();
            }else if(ac.size()&&ac.top() > abc.top() && ac.top() > bc.top()){
                zv += ac.top();
                ac.pop();
            }else{
                if(bc.size())
                {
                    zv += bc.top();
                    bc.pop();
                }else if(ab.size()){
                    zv += ab.top();
                    ab.pop();
                }else{
                    zv += abc.top();
                    abc.pop();
                }
            }
        }
        cout << xv+yv+zv << endl;
    }

    return 0;
}
