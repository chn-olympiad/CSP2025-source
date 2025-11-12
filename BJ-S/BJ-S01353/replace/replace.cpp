#include<bits/stdc++.h>
using namespace std;
struct e{
    int i;
    int fd;
    int ld;
};
struct node{
    //int i;
    string s1;
    string s2;
    vector<e> son;
};
vector<node> l;
string l1[200001];
string l2[200001];
map<string, node> m;
int main(){
    ifstream ifs;
    ifs.open("replace.in");
    int n,q;
    ifs >> n >> q;
    ofstream ofs;
    ofs.open("replace.out");
    for(int i = 1; i<=n; i++){
        ifs >> l1[i];
        ifs >> l2[i];
        int fd,ld;
        ld = 0;
        fd = 0;
        bool ischangefd = false;
       // if()
        for(int j = 0 ; j < l1[i].length();  j++){
            if(l1[i][j] != l2[i][j]){
                if(!ischangefd){
                    fd = j;
                    ischangefd = true;
                }else{
                    ld = j;
                }

            }
        }
        //if(ld == 0 && fd == 0) continue;
        if(ld == 0) ld = fd;
        string s1 = l1[i].substr(fd,ld-fd+1);
        string s2  =  l2[i].substr(fd,ld-fd+1);
        bool status = false;
        /*for(int j = 0; j < l.size(); j++){
            if(s1 == l[j].s1&&s2 == l[j].s2){
                e t;
                t.i = i;
                t.fd = fd;
                t.ld = ld;
                l[j].son.push_back(t);
                status = true;
                break;
            }
        }
        if(!status){
            node t0;
            t0.s1 = s1;
            t0.s2 = s2;
            l.push_back(t0);
            //l[l.size()-1].son.push_back(i);
            e t;
            t.i = i;
            t.fd = fd;
            t.ld = ld;
            l[l.size()-1].son.push_back(t);
        }*/
        e t;
        t.i = i;
        t.fd = fd;
        t.ld = ld;
        m[s1+" "+s2].son.push_back(t);


    }
    for(int i = 0; i < q; i++){
        int cnt = 0;
        string s1, s2;
        ifs >> s1 >> s2;
        if(s1.length() != s2.length()){
            ofs << 0 << endl;
            continue;
        }
        int ld = 0;
        int fd = 0;
        bool isfdchange = false;
        for(int j = 0 ; j < s1.length(); j++){
            if(s1[j] != s2[j]){
                if(!isfdchange){
                    fd = j;
                    isfdchange = true;
                }else{
                    ld = j;
                }

            }
        }
        if(ld == 0) ld =fd;
        string r1 = s1.substr(fd,ld-fd+1);
        string r2 = s2.substr(fd,ld-fd+1);
        //for(int j = 0; j< l.size(); j++){
        if(m.find(r1+" "+r2) == m.end()){
            ofs << 0 << endl;
            continue;
        }
        node t1 = m[r1+" "+r2];
            //if(l[j].s1 == r1 && l[j].s2 == r2){
            //if(t1.s1 == r1 && t1.s2 == r2){
                //for(int k = 0; k < l[j].son.size(); k++){
                for(int k = 0; k < t1.son.size(); k++){
                    bool status = true;
                    //e t = l[j].son[k];
                    e t = t1.son[k];
                    if(fd-t.fd < 0) continue;
                    for(int h = fd-t.fd; h >= 0 && h < fd - t.fd + l1[t.i].length(); h++){
                        if(s1[h] != l1[t.i][h-(fd-t.fd)]){
                            status = false;
                            break;
                        }
                    }
                    if(status){
                        cnt ++;
                    }
                }
                //break;
            //}
        //}
        ofs << cnt << endl;

    }

    //ofs << n;
    return 0;
}
